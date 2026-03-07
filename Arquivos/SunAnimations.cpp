#include "SunAnimations.h"
/*

float InterpolationEngine(float start,float end,float duration,EaseTypes ea,float dir){
switch(ea){
case EaseTypes::EaseIn:{
  return (start + (end - start) * (duration * duration)) * dir;
  break;
}
case EaseTypes::EaseInOut:{
  if(duration < 0.5){
    return (start + (end - start) * (1 - std::pow(1 - duration,2) )) * dir;
  }
  else if(duration > 0.5){
      return (start + (end - start) * (duration * duration)) * dir;
  }
  break;
}
case EaseTypes::EaseOut:{
  return (start + (end - start) * (1 - std::pow(1 - duration,2) )) * dir;
break;
};
case EaseTypes::None:{
return (start + (end - start) * duration) * dir;
break;
}
}
return 0;
};


*/
float GetAnimationProperties(Component* c,Animations a){
switch(a.Propertie){
  case AnimationProperties::X:
  return c->GetX().ValueResolved;
  break;
   case AnimationProperties::Y:
  return c->GetY().ValueResolved;
  break;
   case AnimationProperties::R:
  return c->GetRGBA()->R;
  break;
  case AnimationProperties::B:
  return c->GetRGBA()->B;
  break;
  case AnimationProperties::G:
  return c->GetRGBA()->G;
  break;
  case AnimationProperties::Alpha:
  return c->GetRGBA()->A;
  break;
  case AnimationProperties::Height:
  return c->GetHeight().ValueResolved;
  break;
  case AnimationProperties::Width:
  return c->GetWidth().ValueResolved;
  break;
}
return 0.0;
};

/*
void ApplyValue(float v, Component* c,Animations a){
   switch(a.Propertie){
    case AnimationProperties::X:{
      UnitClass u;
      u.Unit = UnitType::Pixel;
      u.Value = v;
       c->SetX(u);
      break;
    }
   }
};


void render(float initprop,Component* c,Animations ia,SunAnimation a){


  float duration = a.GetDuration();
  float enlapsed = SunCore::instance().SunTime.GetTime() - a.GetStartTime();
  float time = duration / enlapsed;
   int dir = 0;
   
   if(initprop - ia.Target > 0){
    dir = 1;
   }
   else if(initprop - ia.Target < 0){
    dir = -1;
   }

   float interpoledvalue = InterpolationEngine(initprop,ia.Target,time,ia.EaseType,dir);


   ApplyValue(interpoledvalue,c,ia);
   
   if(std::abs(GetAnimationPropertie(c,ia) - ia.Target) != 0){
   
    render(initprop,c,ia,a);
   }

  
};


void RenderAnimation(Component* c,SunAnimation a){
  for(auto ia : a.GetAnimations()){
      float initprop = GetAnimationPropertie(c,ia);
   render(ia.Get(),c,ia,a);

  };
  

}

*/

void SunAnimationsRender::ResolveTarget(Animations& a,Component* c){
 switch(a.Propertie){
  case AnimationProperties::X:{
    switch(a.Target.Unit){
      case UnitType::Pixel:{
        float px = 0.0f;
        if(c->GetOwner()){
           if(c->GetOwner()->Parent){
            Component* p = c->GetOwner()->Parent->ComponentClass;
            px = p->GetX().RenderValue;
           }
      }
       a.Target.ValueResolved = a.Target.Value + px;
       break;
    }
      case UnitType::Percent:{
        float pw = SunCore::instance().WindowWidth;
        float px = 0.0f;
        if(c->GetOwner()){
           if(c->GetOwner()->Parent){
            Component* p = c->GetOwner()->Parent->ComponentClass;
            pw = p->GetWidth().ValueResolved;
            px = p->GetX().RenderValue;
           }
           a.Target.ValueResolved = px + (pw * a.Target.Value);
        }  
        break;
      }
    }
    break;
  }
 }
};


void SunAnimationsRender::ResolveInitTarget(Animations& a,Component* c){
 switch(a.Propertie){
  case AnimationProperties::X:{
    switch(a.Target.Unit){
      case UnitType::Pixel:{
        float px = 0.0f;
        if(c->GetOwner()){
           if(c->GetOwner()->Parent){
            Component* p = c->GetOwner()->Parent->ComponentClass;
            px = p->GetX().RenderValue;
           }
      }
       a.GetFixedInitValue().ValueResolved = a.GetFixedInitValue().Value + px;
       break;
    }
      case UnitType::Percent:{
        float pw = SunCore::instance().WindowWidth;
        float px = 0.0f;
        if(c->GetOwner()){
           if(c->GetOwner()->Parent){
            Component* p = c->GetOwner()->Parent->ComponentClass;
            pw = p->GetWidth().ValueResolved;
            px = p->GetX().RenderValue;
           }
           a.GetFixedInitValue().ValueResolved = px + (pw * a.GetFixedInitValue().Value);
        }  
        break;
      }
    }
    break;
  }
 }
};

void SunAnimationsRender::PlayAnimation(std::string ComponentId,SunAnimation Animation){
    auto ct = SunCore::instance().SunWorld.GetWorldComponentsMap().find(ComponentId);
    if(ct == SunCore::instance().SunWorld.GetWorldComponentsMap().end()){
    return;
    }
    for(Animations& a :Animation.GetAnimations()){
    float prop = GetAnimationProperties(ct->second.get(),a);
    if(a.GetFixedInit()){
      ResolveInitTarget(a,ct->second.get());
     a.Init(a.GetFixedInitValue().ValueResolved);
    }else{
    a.Init(prop);
    }
    ResolveTarget(a,ct->second.get());
    }

   Animation.SetStartTime();
   
    

    SunCore::instance().SunAnimations.AddActiveAnimation(ComponentId,Animation);
};







