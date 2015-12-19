#pragma once
#include <BWAPI.h>

#include <BWTA.h>
#include <windows.h>
#include <vector>

extern bool analyzed;
extern bool analysis_just_finished;
extern BWTA::Region* home;
extern BWTA::Region* enemy_base;
DWORD WINAPI AnalyzeThread();

using namespace BWAPI;
using namespace BWTA;

class ExampleAIModule : public BWAPI::AIModule
{
public:
	//Methods inherited from BWAPI:AIModule
	virtual void onStart();
	virtual void onEnd(bool isWinner);
	virtual void onFrame();
	virtual void onSendText(std::string text);
	virtual void onReceiveText(BWAPI::Player* player, std::string text);
	virtual void onPlayerLeft(BWAPI::Player* player);
	virtual void onNukeDetect(BWAPI::Position target);
	virtual void onUnitDiscover(BWAPI::Unit* unit);
	virtual void onUnitEvade(BWAPI::Unit* unit);
	virtual void onUnitShow(BWAPI::Unit* unit);
	virtual void onUnitHide(BWAPI::Unit* unit);
	virtual void onUnitCreate(BWAPI::Unit* unit);
	virtual void onUnitDestroy(BWAPI::Unit* unit);
	virtual void onUnitMorph(BWAPI::Unit* unit);
	virtual void onUnitRenegade(BWAPI::Unit* unit);
	virtual void onSaveGame(std::string gameName);
	virtual void onUnitComplete(BWAPI::Unit *unit);

	//Own methods
	void drawStats();
	void drawTerrainData();
	void showPlayers();
	void showForces();
	void initializeBuildingPositions();
	bool buildAtPos(Unit* worker, TilePosition pos, BWAPI::UnitType building);
	Position findGuardPoint();

private:
	std::vector <Unit*> workers;
	std::vector <Unit*> marines;
	std::vector <Unit*> medics;
	std::vector <Unit*> commandCenters;
	std::vector <Unit*> barracks;
	std::vector <Unit*> factories;
	std::vector <Unit*> academies;
	std::vector <Unit*> toBuild;
	std::vector <TilePosition*> buildingPos; 
<<<<<<< HEAD
	Unit* refinery;
=======
	int posMultiplier;
>>>>>>> ccab0a4c1b30d1c084943179955e83e2db772569
};
