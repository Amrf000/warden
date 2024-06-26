#include "Db.h"
#include "WowClientDB_Base.h"
#include "WowClientDB.h"

WowClientDB<AchievementRec> g_achievementDB;
WowClientDB<Cfg_CategoriesRec> g_cfg_CategoriesDB;
WowClientDB<Cfg_ConfigsRec> g_cfg_ConfigsDB;
WowClientDB<ChrRacesRec> g_chrRacesDB;

void LoadDB(WowClientDB_Base *db, const char *filename, int32_t linenumber) {
    db->Load(filename, linenumber);
};

void StaticDBLoadAll(void (*loadFn)(WowClientDB_Base *, const char *, int32_t)) {
    loadFn(&g_achievementDB, __FILE__, __LINE__);
    loadFn(&g_cfg_CategoriesDB, __FILE__, __LINE__);
    loadFn(&g_cfg_ConfigsDB, __FILE__, __LINE__);
    loadFn(&g_chrRacesDB, __FILE__, __LINE__);
};

void ClientDBInitialize() {
    // TODO

    StaticDBLoadAll(LoadDB);

    // TODO
}
