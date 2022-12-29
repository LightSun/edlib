#include "dtext.h"
#include "edlib.h"

static inline std::string _alg_2_str(int alg){
    switch (alg) {
    case 0:
        return "match";

    case 1:
        return "insert_2_target";

    case 2:
        return "insert_2_query";

    case 3:
        return "mismatch";
    default:
        break;
    }
    return "";
}

int dtext_compute_distance(const std::string& main, const std::string& query){
    //edlibDefaultAlignConfig()
//    EdlibAlignConfig c = edlibNewAlignConfig(-1, EDLIB_MODE_NW,
//                                             EDLIB_TASK_PATH, NULL, 0);

//    EdlibAlignResult result = edlibAlign(main.data(), main.length(),
//               query.data(), query.length(), c);
//    int dis = result.editDistance;
//    for(int i = 0 ; i < result.alignmentLength ; ++i){
//        std::string str = _alg_2_str(result.alignment[i]);
//        printf("alignment: index = %d, ret = %s\n", i, str.data());
//    }
//    for(int i = 0 ; i < result.numLocations ; ++i){
//        int start = result.startLocations[i];
//        int end = result.endLocations[i];
//        printf("locations(%d): start = %d, end = %d\n", i, start, end);
//    }
    EdlibAlignResult result = edlibAlign(main.data(), main.length(),
               query.data(), query.length(), edlibDefaultAlignConfig());
    int dis = result.editDistance;
    edlibFreeAlignResult(result);
    return dis;
}
