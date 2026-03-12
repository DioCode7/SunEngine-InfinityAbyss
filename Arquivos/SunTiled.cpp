#include "SunTiled.h"
#include "SunFunctions.h"

void Tile::SetTexture(std::string id){
TileTexture = SunCore::instance().SunRenderCore.GetTexture(id);
};

void SunTiled::AddTiledMap(std::string mapid,std::string mappath){
 std::ifstream file(mappath);
 j map;
 file>>map;

auto NewMap = std::make_unique<TiledMap>();
NewMap->SetMapFile(map); 
 TiledMaps.emplace(mapid,std::move(NewMap));
 auto* TiledMap = GetTiledMap(mapid);
 int height = map["height"];
 int width = map["width"];
 int tile_height = map["tileheight"];
 int tile_width = map["tilewidth"];
 TiledMap->MapHeight = height;
 TiledMap->MapWidth = width;
 TiledMap->TileWidth = tile_width;
 TiledMap->TileHeight = tile_height;
 TiledMap->SetName(mapid);
};


void CreateTile(Tile* tile,float worldX,float worldY,Scene* s,std::string gid,float opacity,int zIndex,float width = 0,float height = 0){

  UnitClass x;
  x.Unit = UnitType::Pixel;
  x.Value = worldX;
    UnitClass y;
y.Unit = UnitType::Pixel;
  y.Value = worldY;
      UnitClass w;
w.Unit = UnitType::Pixel;

      UnitClass h;
h.Unit = UnitType::Pixel;
  
  if(width == 0 && height == 0){
      h.Value = tile->TileHeight;
        w.Value = tile->TileWidth;
  }else{
     h.Value = height;
        w.Value = width;
  }

 
SunRender sr;
 std::string cid = tile->GetName() + gid + std::to_string(x.Value) + std::to_string(y.Value);
auto c = std::make_unique<Component>(cid,
w,h,x,y,OriginClass::Start,OriginClass::Start);
c->SetRGBA(1,1,1,opacity);
c->SetzIndex(zIndex);
c->SetTexture(tile->GetTexture()->Id);

sr.AddSprite(std::move(c),s);

if(tile->GetMaterial() != "SunNull"){
SunCore::instance().SunWorld.GetWorldComponentsMap().find(cid)->second->AddMaterial(tile->GetMaterial());
}


  
};


void SunTiled::AddLayerToWorld(std::string Map,std::string Layer,Scene* OwnerScene){
 auto* m = GetTiledMap(Map);
 auto* layer = m->GetLayer(Layer);
 auto map = m->GetMapFile();
 j* l = m->FindLayer(Layer);
 auto& layer_type = (*l)["type"];
 if(layer_type == "tilelayer"){
 auto& data = (*l)["data"];

for(int i = 0; i < data.size(); i++){

    int gid = data[i];

    if(gid != 0){
        
int x = i % m->MapWidth;
int y = i / m->MapWidth;


int flippedY = (m->MapHeight - 1) - y;

float worldX = x * m->TileWidth;
float worldY = y * m->TileHeight;

float offsety = m->MapHeight * m->TileHeight;
worldY -= offsety;
  Tile* Tile; 
    Tile = m->GetTileWithGID(gid);
   float opacity = (*l)["opacity"];
  auto zIndexProp = m->FindPropertie((*l)["properties"],"zIndex");
  int zIndex = zIndexProp["value"];
  
   
if(Tile){
  CreateTile(Tile,worldX,worldY,OwnerScene,std::to_string(gid),opacity,zIndex);


  if(Tile->jsonTile.contains("tiles")){
    auto tiles = Tile->jsonTile["tiles"];
    for(int ti = 0;ti<tiles.size();ti++){ 
    if(tiles[ti].contains("objectgroup")){
      auto& objgroup = tiles[ti]["objectgroup"]["objects"];
      for(int i = 0;i<objgroup.size();i++){
       auto& obj = objgroup[i];
       if(obj.contains("properties")){
        auto& props = obj["properties"];
        for(int ii = 0;ii<props.size();ii++){
          auto propname = props[ii]["name"]; 
          if(propname == "SunBody"){
            auto boolbody = props[ii]["value"]; 
            if(boolbody == true){
              auto sb=std::make_unique<SunBodys>();
              auto b = std::make_unique<Body>();
              float bw = obj["width"];
              float bh = obj["height"];
              float offsetx = obj["x"];
              float offsety = obj["y"];

              b->OffsetX = worldX + offsetx;
              b->OffsetY = (worldY + offsety);
              auto bcollision = m->FindPropertie(obj["properties"],"SunCollisionLayer");
              auto& collisionlayer = bcollision["value"];
              b->SetCollisionLayer(collisionlayer);

              auto bp = std::make_unique<BodySunPhysic>();
              bp->SetMass(100);
              
              b->SetBodySunPhysic(std::move(bp));
              b->Height = bh;
              b->Width = bw;
                 std::string name = Tile->jsonTile["name"];
              sb->AddBody(name + std::to_string(gid) + std::to_string(worldX) + std::to_string(worldY),
             std::move(b));
             sb->CreateStaticBody(name + std::to_string(gid) + std::to_string(worldX) + std::to_string(worldY)+"SunBody",std::move(sb));
            }
          }
        }
       }
      }
    }
      
  }
}
}    
}
}
 }else if(layer_type == "objectgroup"){

auto& objects = (*l)["objects"];

for(int i = 0; i < objects.size(); i++){

    auto& obj = objects[i];

    if(!obj.contains("gid")) continue;

    int gid = obj["gid"];

    float worldX = obj["x"];
    float worldY = obj["y"];

    float offsety = m->MapHeight * m->TileHeight;
    worldY -= offsety;

    Tile* Tile = m->GetTileWithGID(gid);

    float w = obj["width"];
    float h = obj["height"];
    float opacity = (*l)["opacity"];
    auto zIndexProp = m->FindPropertie((*l)["properties"],"zIndex");
  int zIndex = zIndexProp["value"];

    if(Tile){

        worldY -= h;

        CreateTile(Tile,worldX,worldY,OwnerScene,std::to_string(gid),opacity,zIndex,w,h);
    }
}
}


};

void TiledMap::AddLayer(std::string id,std::unique_ptr<TileLayer>t){
  t->MapOwner = this;
  t->SetName(id);
  
 MapLayers.emplace(id,std::move(t));
};


void TileLayer::AddTile(int gid){
   LayerTiles.push_back(gid);
};

void Tile::SetMaterial(std::string MaterialId){
 TileMaterial = MaterialId;
};