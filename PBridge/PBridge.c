#include "PBridge.h"

pBool pyExecute(char *script) {
    FILE *fp = fopen("_cache_scr_0_.py","w");
    if(fp == NULL) {
        return pFalse;
    }
    fputs(script,fp);
    fclose(fp);
    FILE *shared = fopen(SHARED_DATA_PATH,"w");
    fclose(shared);
    system("python _cache_scr_0_.py");
    remove("_cache_scr_0_.py");
    return pTrue;
}
void clearSharedData(void) {
    remove(SHARED_DATA_PATH);
}
void clearPyLibCache(void) {
    remove("PBridgePython.pyc");
}
void clearPyLibWithName(char *cacheName) {
    char buf[1024];
    sprintf(buf,"%s.pyc",cacheName);
    remove(buf);
}
void pyRuntime(void) {
    pyExecute("import pyRunMain as m\nimport sys\nm.main(sys)");
    clearPyLibWithName("pyRunMain");
}
pBool winPyExecute(char *script) {
    FILE *fp = fopen("_cache_scr_0_.py","w");
    if(fp == NULL) {
        return pFalse;
    }
    fputs(script,fp);
    fclose(fp);
    FILE *shared = fopen(SHARED_DATA_PATH,"w");
    fclose(shared);
    system("py _cache_scr_0_.py");
    remove("_cache_scr_0_.py");
    return pTrue;

}
