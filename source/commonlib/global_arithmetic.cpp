#include "global_arithmetic.h"

Arithmetic_Codec acodec;
Adaptive_Data_Model aColor;
Adaptive_Data_Model a3OT_L(3);
Adaptive_Data_Model a3OT_A(3);
Adaptive_Data_Model a3OT_B(3);
Adaptive_Data_Model a3OT_R(3);
Adaptive_Data_Model a3OT_I(3);
Adaptive_Data_Model a3OT_0(3);
Adaptive_Data_Model a3OT_1(3);
Adaptive_Data_Model a3OT_2(3);
Adaptive_Data_Model a3OT_00(3);
Adaptive_Data_Model a3OT_01(3);
Adaptive_Data_Model a3OT_02(3);
Adaptive_Data_Model a3OT_10(3);
Adaptive_Data_Model a3OT_11(3);
Adaptive_Data_Model a3OT_12(3);
Adaptive_Data_Model a3OT_20(3);
Adaptive_Data_Model a3OT_21(3);
Adaptive_Data_Model a3OT_22(3);
Adaptive_Data_Model a3OT_000(3);
Adaptive_Data_Model a3OT_001(3);
Adaptive_Data_Model a3OT_002(3);
Adaptive_Data_Model a3OT_010(3);
Adaptive_Data_Model a3OT_011(3);
Adaptive_Data_Model a3OT_012(3);
Adaptive_Data_Model a3OT_020(3);
Adaptive_Data_Model a3OT_021(3);
Adaptive_Data_Model a3OT_022(3);
Adaptive_Data_Model a3OT_100(3);
Adaptive_Data_Model a3OT_101(3);
Adaptive_Data_Model a3OT_102(3);
Adaptive_Data_Model a3OT_110(3);
Adaptive_Data_Model a3OT_111(3);
Adaptive_Data_Model a3OT_112(3);
Adaptive_Data_Model a3OT_120(3);
Adaptive_Data_Model a3OT_121(3);
Adaptive_Data_Model a3OT_122(3);
Adaptive_Data_Model a3OT_200(3);
Adaptive_Data_Model a3OT_201(3);
Adaptive_Data_Model a3OT_202(3);
Adaptive_Data_Model a3OT_210(3);
Adaptive_Data_Model a3OT_211(3);
Adaptive_Data_Model a3OT_212(3);
Adaptive_Data_Model a3OT_220(3);
Adaptive_Data_Model a3OT_221(3);
Adaptive_Data_Model a3OT_222(3);
Adaptive_Data_Model a3OT_0000(3);
Adaptive_Data_Model a3OT_0001(3);
Adaptive_Data_Model a3OT_0002(3);
Adaptive_Data_Model a3OT_0010(3);
Adaptive_Data_Model a3OT_0011(3);
Adaptive_Data_Model a3OT_0012(3);
Adaptive_Data_Model a3OT_0020(3);
Adaptive_Data_Model a3OT_0021(3);
Adaptive_Data_Model a3OT_0022(3);
Adaptive_Data_Model a3OT_0100(3);
Adaptive_Data_Model a3OT_0101(3);
Adaptive_Data_Model a3OT_0102(3);
Adaptive_Data_Model a3OT_0110(3);
Adaptive_Data_Model a3OT_0111(3);
Adaptive_Data_Model a3OT_0112(3);
Adaptive_Data_Model a3OT_0120(3);
Adaptive_Data_Model a3OT_0121(3);
Adaptive_Data_Model a3OT_0122(3);
Adaptive_Data_Model a3OT_0200(3);
Adaptive_Data_Model a3OT_0201(3);
Adaptive_Data_Model a3OT_0202(3);
Adaptive_Data_Model a3OT_0210(3);
Adaptive_Data_Model a3OT_0211(3);
Adaptive_Data_Model a3OT_0212(3);
Adaptive_Data_Model a3OT_0220(3);
Adaptive_Data_Model a3OT_0221(3);
Adaptive_Data_Model a3OT_0222(3);
Adaptive_Data_Model a3OT_1000(3);
Adaptive_Data_Model a3OT_1001(3);
Adaptive_Data_Model a3OT_1002(3);
Adaptive_Data_Model a3OT_1010(3);
Adaptive_Data_Model a3OT_1011(3);
Adaptive_Data_Model a3OT_1012(3);
Adaptive_Data_Model a3OT_1020(3);
Adaptive_Data_Model a3OT_1021(3);
Adaptive_Data_Model a3OT_1022(3);
Adaptive_Data_Model a3OT_1100(3);
Adaptive_Data_Model a3OT_1101(3);
Adaptive_Data_Model a3OT_1102(3);
Adaptive_Data_Model a3OT_1110(3);
Adaptive_Data_Model a3OT_1111(3);
Adaptive_Data_Model a3OT_1112(3);
Adaptive_Data_Model a3OT_1120(3);
Adaptive_Data_Model a3OT_1121(3);
Adaptive_Data_Model a3OT_1122(3);
Adaptive_Data_Model a3OT_1200(3);
Adaptive_Data_Model a3OT_1201(3);
Adaptive_Data_Model a3OT_1202(3);
Adaptive_Data_Model a3OT_1210(3);
Adaptive_Data_Model a3OT_1211(3);
Adaptive_Data_Model a3OT_1212(3);
Adaptive_Data_Model a3OT_1220(3);
Adaptive_Data_Model a3OT_1221(3);
Adaptive_Data_Model a3OT_1222(3);
Adaptive_Data_Model a3OT_2000(3);
Adaptive_Data_Model a3OT_2001(3);
Adaptive_Data_Model a3OT_2002(3);
Adaptive_Data_Model a3OT_2010(3);
Adaptive_Data_Model a3OT_2011(3);
Adaptive_Data_Model a3OT_2012(3);
Adaptive_Data_Model a3OT_2020(3);
Adaptive_Data_Model a3OT_2021(3);
Adaptive_Data_Model a3OT_2022(3);
Adaptive_Data_Model a3OT_2100(3);
Adaptive_Data_Model a3OT_2101(3);
Adaptive_Data_Model a3OT_2102(3);
Adaptive_Data_Model a3OT_2110(3);
Adaptive_Data_Model a3OT_2111(3);
Adaptive_Data_Model a3OT_2112(3);
Adaptive_Data_Model a3OT_2120(3);
Adaptive_Data_Model a3OT_2121(3);
Adaptive_Data_Model a3OT_2122(3);
Adaptive_Data_Model a3OT_2200(3);
Adaptive_Data_Model a3OT_2201(3);
Adaptive_Data_Model a3OT_2202(3);
Adaptive_Data_Model a3OT_2210(3);
Adaptive_Data_Model a3OT_2211(3);
Adaptive_Data_Model a3OT_2212(3);
Adaptive_Data_Model a3OT_2220(3);
Adaptive_Data_Model a3OT_2221(3);
Adaptive_Data_Model a3OT_2222(3);
Adaptive_Data_Model aMSC_L(36);
Adaptive_Data_Model aMSC_A(36);
Adaptive_Data_Model aMSC_B(36);
Adaptive_Data_Model aMSC_R(36);
Adaptive_Data_Model aMSC_I(3);
Adaptive_Data_Model aMSC_0(27);
Adaptive_Data_Model aMSC_1(27);
Adaptive_Data_Model aMSC_2(27);
Adaptive_Data_Model aMSC_3(27);
Adaptive_Data_Model aMSC_4(27);
Adaptive_Data_Model aMSC_5(27);
Adaptive_Data_Model aMSC_6(27);
Adaptive_Data_Model aMSC_7(27);
Adaptive_Data_Model aMSC_8(27);
Adaptive_Data_Model aMSC_00(27);
Adaptive_Data_Model aMSC_01(27);
Adaptive_Data_Model aMSC_02(27);
Adaptive_Data_Model aMSC_03(27);
Adaptive_Data_Model aMSC_04(27);
Adaptive_Data_Model aMSC_05(27);
Adaptive_Data_Model aMSC_06(27);
Adaptive_Data_Model aMSC_07(27);
Adaptive_Data_Model aMSC_08(27);
Adaptive_Data_Model aMSC_09(27);
Adaptive_Data_Model aMSC_010(27);
Adaptive_Data_Model aMSC_011(27);
Adaptive_Data_Model aMSC_012(27);
Adaptive_Data_Model aMSC_013(27);
Adaptive_Data_Model aMSC_014(27);
Adaptive_Data_Model aMSC_015(27);
Adaptive_Data_Model aMSC_016(27);
Adaptive_Data_Model aMSC_017(27);
Adaptive_Data_Model aMSC_018(27);
Adaptive_Data_Model aMSC_019(27);
Adaptive_Data_Model aMSC_020(27);
Adaptive_Data_Model aMSC_021(27);
Adaptive_Data_Model aMSC_022(27);
Adaptive_Data_Model aMSC_023(27);
Adaptive_Data_Model aMSC_024(27);
Adaptive_Data_Model aMSC_025(27);
Adaptive_Data_Model aMSC_026(27);
Adaptive_Data_Model aMSC_10(27);
Adaptive_Data_Model aMSC_11(27);
Adaptive_Data_Model aMSC_12(27);
Adaptive_Data_Model aMSC_13(27);
Adaptive_Data_Model aMSC_14(27);
Adaptive_Data_Model aMSC_15(27);
Adaptive_Data_Model aMSC_16(27);
Adaptive_Data_Model aMSC_17(27);
Adaptive_Data_Model aMSC_18(27);
Adaptive_Data_Model aMSC_19(27);
Adaptive_Data_Model aMSC_110(27);
Adaptive_Data_Model aMSC_111(27);
Adaptive_Data_Model aMSC_112(27);
Adaptive_Data_Model aMSC_113(27);
Adaptive_Data_Model aMSC_114(27);
Adaptive_Data_Model aMSC_115(27);
Adaptive_Data_Model aMSC_116(27);
Adaptive_Data_Model aMSC_117(27);
Adaptive_Data_Model aMSC_118(27);
Adaptive_Data_Model aMSC_119(27);
Adaptive_Data_Model aMSC_120(27);
Adaptive_Data_Model aMSC_121(27);
Adaptive_Data_Model aMSC_122(27);
Adaptive_Data_Model aMSC_123(27);
Adaptive_Data_Model aMSC_124(27);
Adaptive_Data_Model aMSC_125(27);
Adaptive_Data_Model aMSC_126(27);
Adaptive_Data_Model aMSC_20(27);
Adaptive_Data_Model aMSC_21(27);
Adaptive_Data_Model aMSC_22(27);
Adaptive_Data_Model aMSC_23(27);
Adaptive_Data_Model aMSC_24(27);
Adaptive_Data_Model aMSC_25(27);
Adaptive_Data_Model aMSC_26(27);
Adaptive_Data_Model aMSC_27(27);
Adaptive_Data_Model aMSC_28(27);
Adaptive_Data_Model aMSC_29(27);
Adaptive_Data_Model aMSC_210(27);
Adaptive_Data_Model aMSC_211(27);
Adaptive_Data_Model aMSC_212(27);
Adaptive_Data_Model aMSC_213(27);
Adaptive_Data_Model aMSC_214(27);
Adaptive_Data_Model aMSC_215(27);
Adaptive_Data_Model aMSC_216(27);
Adaptive_Data_Model aMSC_217(27);
Adaptive_Data_Model aMSC_218(27);
Adaptive_Data_Model aMSC_219(27);
Adaptive_Data_Model aMSC_220(27);
Adaptive_Data_Model aMSC_221(27);
Adaptive_Data_Model aMSC_222(27);
Adaptive_Data_Model aMSC_223(27);
Adaptive_Data_Model aMSC_224(27);
Adaptive_Data_Model aMSC_225(27);
Adaptive_Data_Model aMSC_226(27);
Adaptive_Data_Model aMSC_30(27);
Adaptive_Data_Model aMSC_31(27);
Adaptive_Data_Model aMSC_32(27);
Adaptive_Data_Model aMSC_33(27);
Adaptive_Data_Model aMSC_34(27);
Adaptive_Data_Model aMSC_35(27);
Adaptive_Data_Model aMSC_36(27);
Adaptive_Data_Model aMSC_37(27);
Adaptive_Data_Model aMSC_38(27);
Adaptive_Data_Model aMSC_39(27);
Adaptive_Data_Model aMSC_310(27);
Adaptive_Data_Model aMSC_311(27);
Adaptive_Data_Model aMSC_312(27);
Adaptive_Data_Model aMSC_313(27);
Adaptive_Data_Model aMSC_314(27);
Adaptive_Data_Model aMSC_315(27);
Adaptive_Data_Model aMSC_316(27);
Adaptive_Data_Model aMSC_317(27);
Adaptive_Data_Model aMSC_318(27);
Adaptive_Data_Model aMSC_319(27);
Adaptive_Data_Model aMSC_320(27);
Adaptive_Data_Model aMSC_321(27);
Adaptive_Data_Model aMSC_322(27);
Adaptive_Data_Model aMSC_323(27);
Adaptive_Data_Model aMSC_324(27);
Adaptive_Data_Model aMSC_325(27);
Adaptive_Data_Model aMSC_326(27);
Adaptive_Data_Model aMSC_40(27);
Adaptive_Data_Model aMSC_41(27);
Adaptive_Data_Model aMSC_42(27);
Adaptive_Data_Model aMSC_43(27);
Adaptive_Data_Model aMSC_44(27);
Adaptive_Data_Model aMSC_45(27);
Adaptive_Data_Model aMSC_46(27);
Adaptive_Data_Model aMSC_47(27);
Adaptive_Data_Model aMSC_48(27);
Adaptive_Data_Model aMSC_49(27);
Adaptive_Data_Model aMSC_410(27);
Adaptive_Data_Model aMSC_411(27);
Adaptive_Data_Model aMSC_412(27);
Adaptive_Data_Model aMSC_413(27);
Adaptive_Data_Model aMSC_414(27);
Adaptive_Data_Model aMSC_415(27);
Adaptive_Data_Model aMSC_416(27);
Adaptive_Data_Model aMSC_417(27);
Adaptive_Data_Model aMSC_418(27);
Adaptive_Data_Model aMSC_419(27);
Adaptive_Data_Model aMSC_420(27);
Adaptive_Data_Model aMSC_421(27);
Adaptive_Data_Model aMSC_422(27);
Adaptive_Data_Model aMSC_423(27);
Adaptive_Data_Model aMSC_424(27);
Adaptive_Data_Model aMSC_425(27);
Adaptive_Data_Model aMSC_426(27);
Adaptive_Data_Model aMSC_50(27);
Adaptive_Data_Model aMSC_51(27);
Adaptive_Data_Model aMSC_52(27);
Adaptive_Data_Model aMSC_53(27);
Adaptive_Data_Model aMSC_54(27);
Adaptive_Data_Model aMSC_55(27);
Adaptive_Data_Model aMSC_56(27);
Adaptive_Data_Model aMSC_57(27);
Adaptive_Data_Model aMSC_58(27);
Adaptive_Data_Model aMSC_59(27);
Adaptive_Data_Model aMSC_510(27);
Adaptive_Data_Model aMSC_511(27);
Adaptive_Data_Model aMSC_512(27);
Adaptive_Data_Model aMSC_513(27);
Adaptive_Data_Model aMSC_514(27);
Adaptive_Data_Model aMSC_515(27);
Adaptive_Data_Model aMSC_516(27);
Adaptive_Data_Model aMSC_517(27);
Adaptive_Data_Model aMSC_518(27);
Adaptive_Data_Model aMSC_519(27);
Adaptive_Data_Model aMSC_520(27);
Adaptive_Data_Model aMSC_521(27);
Adaptive_Data_Model aMSC_522(27);
Adaptive_Data_Model aMSC_523(27);
Adaptive_Data_Model aMSC_524(27);
Adaptive_Data_Model aMSC_525(27);
Adaptive_Data_Model aMSC_526(27);
Adaptive_Data_Model aMSC_60(27);
Adaptive_Data_Model aMSC_61(27);
Adaptive_Data_Model aMSC_62(27);
Adaptive_Data_Model aMSC_63(27);
Adaptive_Data_Model aMSC_64(27);
Adaptive_Data_Model aMSC_65(27);
Adaptive_Data_Model aMSC_66(27);
Adaptive_Data_Model aMSC_67(27);
Adaptive_Data_Model aMSC_68(27);
Adaptive_Data_Model aMSC_69(27);
Adaptive_Data_Model aMSC_610(27);
Adaptive_Data_Model aMSC_611(27);
Adaptive_Data_Model aMSC_612(27);
Adaptive_Data_Model aMSC_613(27);
Adaptive_Data_Model aMSC_614(27);
Adaptive_Data_Model aMSC_615(27);
Adaptive_Data_Model aMSC_616(27);
Adaptive_Data_Model aMSC_617(27);
Adaptive_Data_Model aMSC_618(27);
Adaptive_Data_Model aMSC_619(27);
Adaptive_Data_Model aMSC_620(27);
Adaptive_Data_Model aMSC_621(27);
Adaptive_Data_Model aMSC_622(27);
Adaptive_Data_Model aMSC_623(27);
Adaptive_Data_Model aMSC_624(27);
Adaptive_Data_Model aMSC_625(27);
Adaptive_Data_Model aMSC_626(27);
Adaptive_Data_Model aMSC_70(27);
Adaptive_Data_Model aMSC_71(27);
Adaptive_Data_Model aMSC_72(27);
Adaptive_Data_Model aMSC_73(27);
Adaptive_Data_Model aMSC_74(27);
Adaptive_Data_Model aMSC_75(27);
Adaptive_Data_Model aMSC_76(27);
Adaptive_Data_Model aMSC_77(27);
Adaptive_Data_Model aMSC_78(27);
Adaptive_Data_Model aMSC_79(27);
Adaptive_Data_Model aMSC_710(27);
Adaptive_Data_Model aMSC_711(27);
Adaptive_Data_Model aMSC_712(27);
Adaptive_Data_Model aMSC_713(27);
Adaptive_Data_Model aMSC_714(27);
Adaptive_Data_Model aMSC_715(27);
Adaptive_Data_Model aMSC_716(27);
Adaptive_Data_Model aMSC_717(27);
Adaptive_Data_Model aMSC_718(27);
Adaptive_Data_Model aMSC_719(27);
Adaptive_Data_Model aMSC_720(27);
Adaptive_Data_Model aMSC_721(27);
Adaptive_Data_Model aMSC_722(27);
Adaptive_Data_Model aMSC_723(27);
Adaptive_Data_Model aMSC_724(27);
Adaptive_Data_Model aMSC_725(27);
Adaptive_Data_Model aMSC_726(27);
Adaptive_Data_Model aMSC_80(27);
Adaptive_Data_Model aMSC_81(27);
Adaptive_Data_Model aMSC_82(27);
Adaptive_Data_Model aMSC_83(27);
Adaptive_Data_Model aMSC_84(27);
Adaptive_Data_Model aMSC_85(27);
Adaptive_Data_Model aMSC_86(27);
Adaptive_Data_Model aMSC_87(27);
Adaptive_Data_Model aMSC_88(27);
Adaptive_Data_Model aMSC_89(27);
Adaptive_Data_Model aMSC_810(27);
Adaptive_Data_Model aMSC_811(27);
Adaptive_Data_Model aMSC_812(27);
Adaptive_Data_Model aMSC_813(27);
Adaptive_Data_Model aMSC_814(27);
Adaptive_Data_Model aMSC_815(27);
Adaptive_Data_Model aMSC_816(27);
Adaptive_Data_Model aMSC_817(27);
Adaptive_Data_Model aMSC_818(27);
Adaptive_Data_Model aMSC_819(27);
Adaptive_Data_Model aMSC_820(27);
Adaptive_Data_Model aMSC_821(27);
Adaptive_Data_Model aMSC_822(27);
Adaptive_Data_Model aMSC_823(27);
Adaptive_Data_Model aMSC_824(27);
Adaptive_Data_Model aMSC_825(27);
Adaptive_Data_Model aMSC_826(27);
Adaptive_Bit_Model ahead;
Adaptive_Bit_Model aflag;
Adaptive_Bit_Model aGolomb;
Adaptive_Bit_Model aEndFlag;
Adaptive_Bit_Model aChainType;

int chain_mode = 2; // 0: MSC  1: 3OT  2: mix MSC and 3OT

int* codedMap;
int* encCodedMap;
unsigned char* encImg;
int first_color;
int edge_num = 0;
int inner_num = 0;

int numC;

int position_N = 1;
int position_A = 1000;
int position_K = 9;


//int aMSC[9][27] = {
//{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
//{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
//{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
//{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
//{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
//{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
//{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
//{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
//{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 }
//};

//int aMSC[9][27] = {
//{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
//{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
//{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
//{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
//{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
//{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
//{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
//{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
//{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 }
//};

int aMSC[27] = {
1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1
};

//int aMSC[27] = {
//1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1
//};

int P_arr1[9][27] = {
{ 0,13, 5, 2, 0,17,22, 0,23, 1, 1, 3,0,1,1,1,1,1,1,1,1,0,0,0,0,0,0 },
{ 0, 0,37,11, 0, 0, 0, 0, 0, 2, 1,23,1,2,1,2,1,1,1,1,1,4,2,1,0,2,0 },
{ 7,12,22, 9, 2, 3,14, 3, 2, 1, 1,10,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
{ 6, 6,20,14, 5, 2, 4, 7, 1, 1, 1,19,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
{ 0,13, 4, 8, 0,10,12, 0,35, 1, 1, 7,0,1,1,1,0,1,1,1,1,0,0,0,0,0,0 },
{ 0, 4, 3, 1, 0,30,24, 0,18, 1, 1, 2,0,1,1,1,1,1,1,1,1,3,1,1,0,1,0 },
{19, 6, 9, 2, 3, 9,29, 4, 2, 1, 1, 2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
{ 5, 1, 1, 1, 4, 1, 1,45, 4, 1, 1, 1,0,1,1,1,0,1,1,1,1,8,1,1,7,2,6 },
{14, 2, 1, 1, 7, 9, 4,23,17, 1, 1, 1,0,1,1,1,0,1,1,1,1,2,1,1,3,1,2 }
};
int ada_P_arr1[9][27] = {};
int enc_arr1[9][27] = {};
int dec_arr1[9][27] = {};
int num_arr1[9] = {};

int P_arr[9][27][27] = {
{
{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0      },
{ 0,0,33,8,0,0,0,0,0,1,1,24,1,1,1,1,1,1,1,1,1,5,4,1,0,4,0    },
{ 13,10,18,6,6,13,18,9,6,2,1,3,1,2,1,1,1,1,1,1,1,3,1,1,3,2,3 },
{ 4,2,7,6,8,2,2,6,1,2,1,3,1,1,1,1,1,1,1,1,1,2,1,1,1,1,1      },
{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0      },
{ 0,3,3,1,0,30,26,0,15,1,1,1,0,1,1,1,1,1,1,1,1,3,1,1,0,2,0   },
{ 32,2,4,1,4,14,16,4,3,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1   },
{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0      },
{ 16,1,1,1,8,5,4,26,16,1,1,1,0,1,1,1,0,1,1,1,1,3,1,1,3,2,2   },
{ 0,2,1,1,0,2,1,0,2,1,1,1,0,2,1,1,0,0,0,0,0,0,0,0,0,0,0      },
{ 0,3,1,1,0,3,1,0,2,1,1,2,0,1,1,1,0,1,1,0,0,0,0,0,0,0,0      },
{ 4,2,1,1,5,3,2,24,2,1,1,2,0,1,1,1,0,1,1,0,1,5,3,3,3,4,4     },
{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0      },
{ 0,0,1,2,0,0,0,0,0,1,1,1,0,1,1,1,0,0,1,0,0,3,3,2,0,4,0      },
{ 0,2,1,1,0,1,2,0,1,1,1,1,0,1,1,1,0,1,1,0,0,3,2,1,0,1,0      },
{ 1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,0,1,1,0,1,2,1,1,1,1,1      },
{ 0,1,1,1,0,1,1,0,1,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0      },
{ 1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,0,1,1,1,1,1,1,1,1,2,1      },
{ 1,1,1,1,2,1,1,2,1,1,1,1,0,1,1,1,0,1,1,1,1,1,1,1,1,1,1      },
{ 1,1,1,1,1,1,1,3,1,1,1,1,0,1,1,1,0,0,0,0,0,1,1,1,1,1,2      },
{ 1,1,1,1,1,1,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1      },
{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0      },
{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0      },
{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0      },
{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0      },
{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0      },
{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0      }
},

{
{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0     },
{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0     },
{ 11,15,22,5,2,4,19,4,2,1,1,5,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
{ 10,9,21,18,3,3,6,8,2,2,1,18,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0     },
{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0     },
{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0     },
{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0     },
{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0     },
{ 0,15,7,4,0,12,4,0,13,1,1,1,0,1,2,1,0,0,2,0,0,0,0,0,0,0,0  },
{ 0,8,2,1,0,7,3,0,8,1,1,5,0,1,1,1,0,1,1,0,0,0,0,0,0,0,0     },
{ 3,1,1,1,2,1,1,30,2,1,1,1,0,1,1,1,0,1,1,0,1,19,1,2,13,3,8  },
{ 0,3,1,1,0,4,1,0,3,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0     },
{ 0,0,7,2,0,0,0,0,0,1,2,1,0,4,2,2,0,1,1,1,1,12,4,4,0,8,0    },
{ 0,1,2,1,0,6,3,0,2,2,1,3,0,1,1,1,0,1,1,1,1,9,2,1,0,2,0     },
{ 3,3,1,2,3,1,3,14,6,1,1,1,0,1,1,1,0,1,1,1,1,2,1,1,2,2,2    },
{ 0,1,1,1,0,1,1,0,1,1,1,1,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0     },
{ 3,2,2,1,1,1,3,3,1,1,1,3,1,1,1,1,1,1,1,1,1,1,1,1,1,2,1     },
{ 6,2,1,1,2,1,4,2,2,1,1,2,1,1,1,1,1,1,1,1,1,2,2,1,1,2,1     },
{ 1,1,2,1,1,1,1,3,1,1,1,1,0,1,1,1,0,1,1,0,0,2,2,1,2,1,1     },
{ 1,1,2,2,1,1,2,1,2,1,1,1,1,2,1,1,1,1,1,1,1,1,1,1,1,1,1     },
{ 0,0,19,8,0,0,0,0,0,10,4,19,2,9,6,9,1,5,6,3,3,1,0,0,0,0,0  },
{ 0,6,16,4,0,3,3,0,1,2,2,6,0,3,1,1,1,4,2,1,2,2,1,1,0,1,0    },
{ 2,2,2,1,1,2,3,1,2,1,1,1,0,1,2,1,0,1,1,1,1,3,1,1,1,1,1     },
{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0     },
{ 8,4,6,3,4,5,4,1,2,2,1,4,1,2,2,1,1,1,1,1,1,1,1,1,1,1,1     },
{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0     }
},

{
{ 0,35,10,4,0,11,22,0,7,1,1,4,0,1,1,1,1,1,1,1,1,0,0,0,0,0,0 },
{ 0,0,67,8,0,0,0,0,0,1,1,7,1,1,1,1,1,1,1,1,1,2,1,1,0,1,0    },
{ 3,17,37,12,1,3,9,1,2,1,1,6,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1  },
{ 2,9,45,17,1,1,5,1,1,1,2,12,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1  },
{ 0,18,7,8,0,3,11,0,9,1,2,6,0,2,1,1,0,1,1,1,1,0,0,0,0,0,0   },
{ 0,9,16,9,0,14,46,0,16,1,1,6,0,1,2,1,1,1,1,1,1,1,1,4,0,3,0 },
{ 5,11,21,3,2,4,34,2,3,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1  },
{ 18,3,1,4,7,2,3,67,7,1,1,5,0,2,1,1,0,1,1,1,1,3,1,3,3,1,7   },
{ 4,2,7,3,5,1,6,16,9,1,1,1,0,1,1,1,0,1,1,1,1,2,1,2,2,2,4    },
{ 0,13,1,1,0,5,3,0,10,1,1,2,0,1,2,1,0,0,1,0,0,0,0,0,0,0,0   },
{ 0,6,3,1,0,5,4,0,10,2,1,1,0,1,1,1,0,1,1,0,0,0,0,0,0,0,0    },
{ 3,1,1,1,3,1,1,25,1,1,1,1,0,1,1,1,0,1,1,0,1,21,1,1,20,4,11 },
{ 0,1,1,1,0,1,1,0,1,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0     },
{ 0,0,2,1,0,0,0,0,0,1,1,1,0,1,1,1,0,1,1,1,1,3,4,1,0,1,0     },
{ 0,1,1,1,0,4,1,0,1,1,1,2,0,1,1,1,0,1,1,1,1,5,2,1,0,2,0     },
{ 4,1,1,1,2,1,1,4,1,1,1,1,0,1,1,1,0,1,1,1,1,3,2,1,1,1,2     },
{ 0,1,1,1,0,2,1,0,1,1,1,1,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0     },
{ 1,1,1,1,1,1,1,2,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,1     },
{ 2,2,1,1,1,1,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,1,2,2,1     },
{ 2,1,1,1,1,1,1,2,1,1,1,1,0,1,1,1,0,1,1,0,0,1,1,1,3,1,2     },
{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1     },
{ 0,0,2,2,0,0,0,0,0,4,5,3,3,4,2,2,1,2,2,1,2,0,0,0,0,0,0     },
{ 0,1,1,1,0,1,1,0,2,1,1,2,0,3,1,2,1,1,1,1,2,1,0,0,0,0,0     },
{ 1,1,2,1,1,1,1,1,1,1,1,1,0,1,1,1,0,1,1,1,1,1,1,1,1,1,1     },
{ 5,2,2,2,1,1,3,1,2,1,1,3,1,1,2,1,1,1,2,1,1,1,0,0,2,1,1     },
{ 1,2,2,1,2,2,3,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1     },
{ 5,1,4,1,4,2,3,4,1,1,2,2,1,2,1,1,1,1,2,1,1,1,1,0,1,1,1     }
},

{
{ 0,61,16,6,0,7,13,0,6,1,2,11,0,2,1,1,1,1,1,1,1,0,0,0,0,0,0 },
{ 0,0,59,22,0,0,0,0,0,1,2,22,2,1,1,1,1,1,1,1,1,2,1,1,0,1,0  },
{ 2,7,29,22,1,1,7,2,1,1,1,10,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1  },
{ 2,4,28,34,1,2,3,1,1,1,1,20,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1  },
{ 0,10,5,28,0,1,4,0,5,2,2,32,0,1,1,1,0,1,1,1,1,0,0,0,0,0,0  },
{ 0,4,4,1,0,5,7,0,3,1,1,2,0,1,1,1,1,1,1,1,1,1,2,1,0,2,0     },
{ 13,5,15,7,3,5,24,3,3,1,1,5,1,1,1,1,1,1,1,1,1,2,1,1,1,1,2  },
{ 7,3,3,7,22,1,2,76,3,1,1,5,0,1,1,1,0,1,1,1,1,2,2,1,2,1,5   },
{ 3,2,1,1,2,1,1,9,2,1,1,3,0,1,1,1,0,1,1,1,1,2,1,1,1,1,1     },
{ 0,7,1,1,0,1,3,0,8,1,1,1,0,1,1,1,0,0,1,0,0,0,0,0,0,0,0     },
{ 0,4,1,1,0,2,4,0,5,1,1,2,0,1,1,1,0,1,1,0,0,0,0,0,0,0,0     },
{ 5,1,1,1,2,1,1,32,1,1,1,1,0,1,1,1,0,1,1,0,1,28,1,1,16,2,9  },
{ 0,1,1,1,0,1,1,0,2,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0     },
{ 0,0,1,1,0,0,0,0,0,1,1,3,0,1,1,1,0,1,1,1,1,4,3,2,0,3,0     },
{ 0,1,1,1,0,3,2,0,1,1,1,1,0,1,1,1,0,1,1,1,1,2,1,1,0,1,0     },
{ 1,1,1,1,1,1,1,6,1,1,1,1,0,1,1,1,0,1,1,1,1,2,1,1,2,1,1     },
{ 0,1,1,1,0,1,1,0,1,1,1,1,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0     },
{ 1,1,1,1,1,1,1,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2     },
{ 2,2,1,1,1,1,1,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1     },
{ 1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,0,1,1,0,0,1,1,1,1,1,1     },
{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,1,1,1,1,1     },
{ 0,0,2,1,0,0,0,0,0,3,1,2,2,3,1,1,1,2,1,3,1,0,0,0,0,0,0     },
{ 0,1,1,1,0,1,1,0,1,1,1,1,0,1,1,1,1,1,1,1,1,0,0,0,0,0,0     },
{ 1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,0,1,1,1,1,1,0,0,1,0,1     },
{ 1,1,1,3,1,1,3,1,1,1,1,2,1,1,1,1,1,2,1,1,1,1,0,0,1,0,1     },
{ 2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,1,1     },
{ 3,3,2,1,4,1,2,3,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1     }
},

{
{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0     },
{ 0,0,49,15,0,0,0,0,0,2,2,28,1,2,1,1,1,1,2,1,2,12,4,1,0,3,0 },
{ 12,3,3,1,4,4,2,5,2,2,1,1,1,1,1,2,1,1,1,1,1,5,2,1,1,1,1    },
{ 9,1,2,1,13,1,2,36,2,1,1,3,1,2,1,1,1,1,1,1,1,1,1,1,2,1,6   },
{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0     },
{ 0,5,2,2,0,21,16,0,38,2,1,2,0,1,1,1,1,3,1,1,1,8,1,1,0,1,0  },
{ 29,6,3,1,8,10,19,21,3,2,1,3,1,1,1,1,1,1,1,1,1,3,1,1,2,1,4 },
{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0     },
{ 13,1,1,1,12,4,3,28,11,1,1,1,0,1,1,1,0,1,1,1,1,3,1,1,3,1,2 },
{ 0,1,2,1,0,1,1,0,2,1,1,1,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0     },
{ 0,1,2,2,0,2,1,0,2,1,1,2,0,1,1,1,0,1,1,0,0,0,0,0,0,0,0     },
{ 4,1,1,1,4,2,1,27,2,1,1,1,0,1,1,1,0,1,1,0,1,1,1,14,4,1,13  },
{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0     },
{ 0,0,1,1,0,0,0,0,0,1,1,1,0,1,1,1,0,0,0,0,0,1,3,1,0,1,0     },
{ 0,1,1,1,0,1,1,0,1,1,1,1,0,1,1,1,0,1,1,0,0,1,1,1,0,1,0     },
{ 1,1,1,1,1,1,1,1,2,1,1,1,0,1,1,1,0,1,1,0,1,1,1,1,1,1,1     },
{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0     },
{ 1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,0,0,1,0,0,1,1,1,1,1,1     },
{ 1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,0,1,1,0,0,1,1,1,2,1,1     },
{ 1,1,1,1,1,1,1,1,1,0,0,1,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1     },
{ 1,1,1,1,1,1,1,1,1,1,1,2,0,1,1,1,0,1,1,1,1,1,1,1,1,1,1     },
{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0     },
{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0     },
{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0     },
{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0     },
{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0     },
{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0     }
},

{
{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0     },
{ 0,0,43,7,0,0,0,0,0,3,3,19,1,4,1,1,1,1,2,1,1,8,1,1,0,3,0   },
{ 18,7,9,5,4,9,15,6,4,1,2,4,1,2,2,1,1,2,2,1,1,5,1,1,1,1,1   },
{ 5,3,3,2,2,4,5,2,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1     },
{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0     },
{ 0,2,1,1,0,47,16,0,22,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,0,1,0  },
{ 33,2,2,1,5,17,15,4,3,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1  },
{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0     },
{ 10,2,1,1,4,26,5,11,20,1,1,1,0,1,1,1,0,1,1,1,1,1,1,1,2,1,2 },
{ 0,7,2,1,0,1,2,0,1,1,2,2,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0     },
{ 0,1,1,2,0,1,1,0,3,1,1,1,0,1,1,1,0,1,1,0,0,0,0,0,0,0,0     },
{ 3,3,2,1,1,2,1,15,1,1,1,1,0,1,1,1,0,1,1,0,1,5,2,1,4,2,3    },
{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0     },
{ 0,0,1,1,0,0,0,0,0,1,1,2,0,1,1,1,0,0,1,0,0,1,6,1,0,1,0     },
{ 0,1,1,1,0,1,1,0,1,1,1,1,0,1,1,1,0,1,1,0,0,2,2,1,0,1,0     },
{ 1,1,1,1,2,1,1,1,1,1,1,1,0,1,1,1,0,1,1,0,1,2,1,1,1,1,1     },
{ 0,1,1,1,0,1,1,0,1,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0     },
{ 1,2,1,2,1,1,2,1,1,1,1,2,0,1,1,1,0,1,1,1,1,1,1,1,1,2,1     },
{ 2,1,1,1,1,1,2,1,1,1,1,1,0,1,1,1,0,1,1,1,1,1,1,1,1,1,1     },
{ 1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,0,0,0,0,0,1,1,1,2,1,1     },
{ 1,1,2,1,2,1,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,1,1,1,1,1     },
{ 0,0,17,6,0,0,0,0,0,6,1,17,1,4,8,4,1,1,1,1,1,5,1,0,0,1,0   },
{ 0,2,1,1,0,3,2,0,2,2,1,2,0,1,2,1,1,1,2,1,1,1,1,1,0,2,0     },
{ 1,1,1,2,1,1,1,1,2,1,2,1,0,1,1,1,0,1,1,1,1,2,1,1,3,1,1     },
{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0     },
{ 7,1,1,3,2,1,7,2,1,1,1,1,1,3,1,1,1,1,1,1,1,1,1,1,3,1,1     },
{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0     }
},

{
{ 0,4,3,1,0,28,43,0,9,1,1,1,0,1,1,1,1,1,1,1,1,0,0,0,0,0,0   },
{ 0,0,86,6,0,0,0,0,0,4,2,9,1,2,1,2,1,1,2,1,1,2,1,1,0,1,0    },
{ 5,16,11,2,2,5,46,3,1,1,1,3,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1  },
{ 7,9,16,9,2,1,9,1,1,1,1,10,1,2,1,1,1,2,1,1,1,1,1,1,1,1,1   },
{ 0,6,6,1,0,32,38,0,45,1,2,2,0,2,1,1,0,1,2,1,1,0,0,0,0,0,0  },
{ 0,4,4,1,0,14,66,0,5,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,0,1,0   },
{ 11,7,9,1,2,7,45,1,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1   },
{ 19,4,2,1,7,13,7,44,20,1,1,1,0,1,1,1,0,1,1,1,1,6,1,3,10,5,8},
{ 11,3,6,1,8,4,9,22,8,1,1,1,0,1,1,1,0,1,1,1,1,3,1,4,6,2,3   },
{ 0,5,1,1,0,3,5,0,2,1,1,2,0,1,1,1,0,0,1,0,0,0,0,0,0,0,0     },
{ 0,1,1,1,0,2,2,0,3,1,1,1,0,1,1,1,0,1,1,0,0,0,0,0,0,0,0     },
{ 3,1,1,1,2,2,1,20,1,1,1,1,0,1,1,1,0,1,1,0,1,8,2,3,4,6,4    },
{ 0,1,0,0,0,1,2,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0     },
{ 0,0,2,1,0,0,0,0,0,1,1,2,0,1,1,1,0,1,1,0,0,4,3,2,0,1,0     },
{ 0,1,1,1,0,1,1,0,1,1,1,1,0,1,1,1,0,1,1,0,1,2,1,1,0,1,0     },
{ 1,1,1,1,1,1,1,3,2,1,1,1,0,1,1,1,0,2,1,1,1,1,1,1,1,1,1     },
{ 0,1,1,1,0,1,1,0,1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0     },
{ 1,1,1,1,2,1,1,1,1,1,1,2,0,1,1,1,0,1,1,1,1,1,2,1,1,1,1     },
{ 1,1,1,1,1,1,2,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1     },
{ 1,1,1,1,1,1,1,2,1,1,1,1,0,1,1,1,0,0,0,0,0,1,1,1,1,1,1     },
{ 1,1,1,1,1,1,1,1,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1     },
{ 0,0,2,4,0,0,0,0,0,4,2,2,2,3,2,4,1,4,3,1,1,0,0,0,0,0,0     },
{ 0,1,2,1,0,1,1,0,3,1,1,2,0,1,1,1,1,1,1,1,1,1,1,0,0,2,0     },
{ 1,1,1,1,1,1,1,2,1,1,1,1,0,1,1,1,0,1,1,1,1,1,1,1,1,1,1     },
{ 3,2,2,1,1,2,6,1,1,4,1,2,1,1,1,2,1,1,1,1,1,2,0,0,1,1,2     },
{ 2,1,1,1,2,1,1,2,1,1,1,1,1,1,1,2,1,1,1,1,2,1,1,1,1,1,1     },
{ 2,2,2,2,1,1,1,4,1,3,1,4,1,1,1,1,1,1,1,1,1,2,1,0,2,1,3     }
},

{
{ 0,15,5,3,0,9,10,0,38,1,1,5,0,1,1,1,0,1,1,1,1,0,0,0,0,0,0  },
{ 0,0,14,6,0,0,0,0,0,1,1,15,1,1,1,2,1,1,2,1,1,7,4,1,0,3,0   },
{ 3,2,4,1,1,1,1,3,1,1,1,4,1,1,1,1,1,1,1,1,1,4,2,2,3,1,1     },
{ 5,1,3,1,16,1,1,20,1,1,1,3,1,1,1,1,1,1,1,1,1,2,1,1,1,1,1   },
{ 0,18,4,11,0,7,9,0,28,1,1,6,0,1,1,1,0,1,1,1,1,0,0,0,0,0,0  },
{ 0,3,1,1,0,17,9,0,15,1,1,1,0,1,1,1,1,1,1,1,1,7,1,1,0,1,0   },
{ 8,2,2,1,2,4,12,12,2,1,1,3,1,1,1,1,1,1,1,1,1,3,1,1,1,1,1   },
{ 4,1,1,1,4,1,1,56,2,1,1,1,0,1,1,1,0,1,1,1,1,5,1,1,5,1,5    },
{ 11,1,1,1,8,3,3,37,10,1,1,1,0,1,1,1,0,1,1,1,1,3,1,1,2,1,3  },
{ 0,1,1,1,0,2,3,0,1,1,1,1,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0     },
{ 0,1,1,1,0,1,1,0,1,1,1,1,0,1,1,1,0,1,1,0,0,0,0,0,0,0,0     },
{ 2,1,1,2,2,1,1,16,1,1,1,1,0,1,1,1,0,1,1,0,1,2,1,4,3,1,3    },
{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0     },
{ 0,0,2,1,0,0,0,0,0,1,1,1,0,1,1,1,0,0,0,0,0,2,2,2,0,1,0     },
{ 0,1,1,1,0,2,1,0,1,1,1,1,0,1,1,1,0,1,1,0,0,1,1,1,0,1,0     },
{ 1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,0,1,1,0,1,1,1,1,1,1,1     },
{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0     },
{ 1,1,1,1,1,1,2,1,1,1,1,1,0,1,1,1,0,0,0,0,0,1,1,1,1,1,1     },
{ 1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,0,1,1,0,0,1,1,1,1,1,1     },
{ 1,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,2,2,1     },
{ 1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,0,0,1,0,0,1,1,1,1,1,1     },
{ 0,0,14,19,0,0,0,0,0,2,1,47,1,1,1,1,1,1,1,1,1,1,1,1,0,1,0  },
{ 0,15,5,3,0,2,3,0,5,1,1,6,0,2,1,2,1,1,1,1,1,3,1,1,0,1,0    },
{ 9,7,1,12,2,1,2,23,2,2,1,18,0,1,1,1,0,1,1,1,1,1,1,3,3,1,1  },
{ 8,4,9,11,3,1,4,5,2,2,1,41,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1   },
{ 6,6,22,14,1,4,9,9,4,3,1,10,1,1,1,1,1,1,1,1,1,3,2,1,1,2,1  },
{ 8,4,7,7,6,1,3,5,1,2,2,37,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1    }
},


{
{ 0,3,2,1,0,13,6,0,55,1,1,2,0,1,1,1,0,1,1,1,1,0,0,0,0,0,0   },
{ 0,0,16,1,0,0,0,0,0,2,1,9,1,2,1,2,1,1,1,1,2,6,1,1,0,1,0    },
{ 4,4,2,1,1,6,5,4,1,2,1,3,1,1,1,1,1,1,1,1,1,2,1,1,1,1,1     },
{ 3,1,1,2,4,1,2,10,1,1,1,1,1,1,1,1,1,1,1,1,1,2,1,1,1,1,1    },
{ 0,6,2,1,0,12,8,0,72,1,1,2,0,1,1,1,0,1,1,1,1,0,0,0,0,0,0   },
{ 0,2,2,1,0,34,10,0,37,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,0,1,0  },
{ 34,5,3,2,17,7,10,17,2,1,1,1,1,1,1,1,1,1,1,1,1,4,1,1,2,1,4 },
{ 12,2,1,1,6,2,1,36,13,1,1,1,0,1,1,1,0,1,1,1,1,3,1,1,4,2,3  },
{ 20,2,1,1,8,9,3,13,26,1,1,1,0,1,1,1,0,1,1,1,1,1,1,1,1,1,1  },
{ 0,1,3,1,0,1,2,0,3,1,1,1,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0     },
{ 0,1,2,1,0,1,1,0,1,1,1,1,0,1,1,1,0,1,1,0,0,0,0,0,0,0,0     },
{ 2,1,1,1,2,1,1,13,1,1,1,1,0,1,1,1,0,1,1,0,1,1,2,1,3,1,4    },
{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0     },
{ 0,0,1,1,0,0,0,0,0,1,1,1,0,1,1,1,0,0,0,0,0,1,1,1,0,1,0     },
{ 0,2,1,1,0,1,1,0,1,1,1,1,0,1,1,1,0,1,1,0,0,1,1,1,0,1,0     },
{ 1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,0,1,1,0,1,1,1,1,1,1,1     },
{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0     },
{ 1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,0,0,1,0,0,2,1,1,1,1,1     },
{ 1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,0,1,1,0,0,1,1,1,1,1,1     },
{ 1,1,1,1,1,1,1,3,1,0,1,1,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1     },
{ 1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,0,1,1,1,1,1,1,1,1,1,1     },
{ 0,0,10,9,0,0,0,0,0,3,3,25,2,1,2,5,1,1,1,1,1,3,2,1,0,3,0   },
{ 0,2,2,1,0,1,1,0,2,1,1,1,0,1,1,1,1,1,1,1,1,2,1,1,0,1,0     },
{ 3,1,2,1,2,1,1,2,2,1,1,1,0,1,1,1,0,1,1,1,1,1,1,1,5,3,1     },
{ 3,4,17,6,1,3,6,3,2,1,5,13,1,2,2,3,1,1,3,1,1,1,1,1,1,1,1   },
{ 5,3,3,2,2,1,9,1,3,1,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1     },
{ 7,2,9,4,1,3,4,1,1,2,1,14,1,1,1,3,1,2,2,1,1,1,1,1,2,2,2    }
}

};
int ada_P_arr[9][27][27] = {};
int enc_arr[9][27][27] = {};
int dec_arr[9][27][27] = {};
int num_arr[9][27] = {};

int get_direction2(int direction)
{
	if (direction < 9) return direction;
	if (direction == 9|| direction == 12) return 0;
	if (direction == 13|| direction == 21) return 1;
	if (direction == 17|| direction == 24) return 2;
	if (direction == 20|| direction == 26) return 3;
	if (direction == 10|| direction == 16) return 4;
	if (direction == 14|| direction == 22) return 5;
	if (direction == 18|| direction == 25) return 6;
	if (direction == 11|| direction == 19) return 7;
	if (direction == 15|| direction == 23) return 8;
}

void enc_global()
{
	//for (int i = 0; i < 9; i++)
	//{
	//	for (int j = 12; j <= 20; j++)
	//	{
	//		if (P_arr1[i][j]) acodec.encode(aMSC[i][j], aflag);
	//	}
	//}
	if (chain_mode == 0 || chain_mode == 2)
	{
		for (int i = 0; i < 9; i++)
		{
			acodec.encode(aMSC[i + 12], aflag);
		}
	}
}

void dec_global()
{
	//for (int i = 0; i < 9; i++)
	//{
	//	for (int j = 12; j <= 20; j++)
	//	{
	//		if (P_arr1[i][j]) aMSC[i][j] = acodec.decode(aflag);
	//	}
	//}
	if (chain_mode == 0|| chain_mode == 2)
	{
		for (int i = 0; i < 9; i++)
		{
			aMSC[i + 12] = acodec.decode(aflag);
		}
	}
}

void reset_arithmetic()
{
	int P_arr1_refine[9][27];
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 27; j++)
		{
			P_arr1_refine[i][j] = P_arr1[i][j];

			//if (P_arr1[i][j]) P_arr1_refine[i][j] = 1;
			//else P_arr1_refine[i][j] = 0;

			if (j >= 12 && j <= 20 && aMSC[j] == 0) P_arr1_refine[i][j] = 0;
		}
	}

	int P_arr_refine[9][27][27];
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 27; j++)
		{
			for (int k = 0; k < 27; k++)
			{
				P_arr_refine[i][j][k] = P_arr[i][j][k];

				//if (P_arr[i][j][k]) P_arr_refine[i][j][k] = 1;
				//else P_arr_refine[i][j][k] = 0;

				if (k >= 12 && k <= 20 && aMSC[k] == 0) P_arr_refine[i][j][k] = 0;
			}
		}
	}


	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 27; j++)
		{
			int enc_index = 0;
			for (int k = 0; k < 27; k++)
			{
				if (P_arr_refine[i][j][k] > 0)
				{
					enc_arr[i][j][k] = enc_index;
					dec_arr[i][j][enc_index] = k;
					enc_index++;
				}
			}
			num_arr[i][j] = enc_index;
			if (enc_index > 0)
			{
				for (int k = 0; k < enc_index; k++)
				{
					ada_P_arr[i][j][k] = P_arr_refine[i][j][dec_arr[i][j][k]];
				}
			}
		}
	}

	for (int i = 0; i < 9; i++)
	{
		int enc_index = 0;
		for (int k = 0; k < 27; k++)
		{
			if (P_arr1_refine[i][k] > 0)
			{
				enc_arr1[i][k] = enc_index;
				dec_arr1[i][enc_index] = k;
				enc_index++;
			}
		}
		num_arr1[i] = enc_index;
		if (enc_index > 0)
		{
			for (int k = 0; k < enc_index; k++)
			{
				ada_P_arr1[i][k] = P_arr1_refine[i][dec_arr1[i][k]];
			}
		}
	}

	a3OT_L.reset();
	a3OT_A.reset();
	a3OT_B.reset();
	a3OT_R.reset();
	a3OT_I.reset();
	a3OT_0.reset();
	a3OT_1.reset();
	a3OT_2.reset();
	a3OT_00.reset();
	a3OT_01.reset();
	a3OT_02.reset();
	a3OT_10.reset();
	a3OT_11.reset();
	a3OT_12.reset();
	a3OT_20.reset();
	a3OT_21.reset();
	a3OT_22.reset();
	a3OT_000.reset();
	a3OT_001.reset();
	a3OT_002.reset();
	a3OT_010.reset();
	a3OT_011.reset();
	a3OT_012.reset();
	a3OT_020.reset();
	a3OT_021.reset();
	a3OT_022.reset();
	a3OT_100.reset();
	a3OT_101.reset();
	a3OT_102.reset();
	a3OT_110.reset();
	a3OT_111.reset();
	a3OT_112.reset();
	a3OT_120.reset();
	a3OT_121.reset();
	a3OT_122.reset();
	a3OT_200.reset();
	a3OT_201.reset();
	a3OT_202.reset();
	a3OT_210.reset();
	a3OT_211.reset();
	a3OT_212.reset();
	a3OT_220.reset();
	a3OT_221.reset();
	a3OT_222.reset();
	a3OT_0000.reset();
	a3OT_0001.reset();
	a3OT_0002.reset();
	a3OT_0010.reset();
	a3OT_0011.reset();
	a3OT_0012.reset();
	a3OT_0020.reset();
	a3OT_0021.reset();
	a3OT_0022.reset();
	a3OT_0100.reset();
	a3OT_0101.reset();
	a3OT_0102.reset();
	a3OT_0110.reset();
	a3OT_0111.reset();
	a3OT_0112.reset();
	a3OT_0120.reset();
	a3OT_0121.reset();
	a3OT_0122.reset();
	a3OT_0200.reset();
	a3OT_0201.reset();
	a3OT_0202.reset();
	a3OT_0210.reset();
	a3OT_0211.reset();
	a3OT_0212.reset();
	a3OT_0220.reset();
	a3OT_0221.reset();
	a3OT_0222.reset();
	a3OT_1000.reset();
	a3OT_1001.reset();
	a3OT_1002.reset();
	a3OT_1010.reset();
	a3OT_1011.reset();
	a3OT_1012.reset();
	a3OT_1020.reset();
	a3OT_1021.reset();
	a3OT_1022.reset();
	a3OT_1100.reset();
	a3OT_1101.reset();
	a3OT_1102.reset();
	a3OT_1110.reset();
	a3OT_1111.reset();
	a3OT_1112.reset();
	a3OT_1120.reset();
	a3OT_1121.reset();
	a3OT_1122.reset();
	a3OT_1200.reset();
	a3OT_1201.reset();
	a3OT_1202.reset();
	a3OT_1210.reset();
	a3OT_1211.reset();
	a3OT_1212.reset();
	a3OT_1220.reset();
	a3OT_1221.reset();
	a3OT_1222.reset();
	a3OT_2000.reset();
	a3OT_2001.reset();
	a3OT_2002.reset();
	a3OT_2010.reset();
	a3OT_2011.reset();
	a3OT_2012.reset();
	a3OT_2020.reset();
	a3OT_2021.reset();
	a3OT_2022.reset();
	a3OT_2100.reset();
	a3OT_2101.reset();
	a3OT_2102.reset();
	a3OT_2110.reset();
	a3OT_2111.reset();
	a3OT_2112.reset();
	a3OT_2120.reset();
	a3OT_2121.reset();
	a3OT_2122.reset();
	a3OT_2200.reset();
	a3OT_2201.reset();
	a3OT_2202.reset();
	a3OT_2210.reset();
	a3OT_2211.reset();
	a3OT_2212.reset();
	a3OT_2220.reset();
	a3OT_2221.reset();
	a3OT_2222.reset();
	float a3OT_Lpro[3] = { 0.4, 0.5, 0.1 }; a3OT_L.setPro(a3OT_Lpro);
	float a3OT_Apro[3] = { 0.4, 0.5, 0.1 }; a3OT_A.setPro(a3OT_Apro);
	float a3OT_Bpro[3] = { 0.2, 0.7, 0.1 }; a3OT_B.setPro(a3OT_Bpro);
	float a3OT_Rpro[3] = { 0.4, 0.5, 0.1 }; a3OT_R.setPro(a3OT_Rpro);
	float a3OT_0pro[3] = { 0.6, 0.3, 0.1 }; a3OT_0.setPro(a3OT_0pro);
	float a3OT_1pro[3] = { 0.4, 0.5, 0.1 }; a3OT_1.setPro(a3OT_1pro);
	float a3OT_2pro[3] = { 0.5, 0.4, 0.1 }; a3OT_2.setPro(a3OT_2pro);
	float a3OT_00pro[3] = { 0.7, 0.2, 0.1 }; a3OT_00.setPro(a3OT_00pro);
	float a3OT_01pro[3] = { 0.1, 0.8, 0.1 }; a3OT_01.setPro(a3OT_01pro);
	float a3OT_10pro[3] = { 0.5, 0.4, 0.1 }; a3OT_10.setPro(a3OT_10pro);
	float a3OT_11pro[3] = { 0.4, 0.5, 0.1 }; a3OT_11.setPro(a3OT_11pro);
	float a3OT_20pro[3] = { 0.7, 0.2, 0.1 }; a3OT_20.setPro(a3OT_20pro);
	float a3OT_000pro[3] = { 0.8, 0.1, 0.1 }; a3OT_000.setPro(a3OT_000pro);
	float a3OT_001pro[3] = { 0.1, 0.8, 0.1 }; a3OT_001.setPro(a3OT_001pro);
	float a3OT_002pro[3] = { 0.1, 0.8, 0.1 }; a3OT_002.setPro(a3OT_002pro);
	float a3OT_010pro[3] = { 0.6, 0.2, 0.2 }; a3OT_010.setPro(a3OT_010pro);
	float a3OT_011pro[3] = { 0.7, 0.2, 0.1 }; a3OT_011.setPro(a3OT_011pro);
	float a3OT_012pro[3] = { 0.4, 0.5, 0.1 }; a3OT_012.setPro(a3OT_012pro);
	float a3OT_020pro[3] = { 0.7, 0.2, 0.1 }; a3OT_020.setPro(a3OT_020pro);
	float a3OT_021pro[3] = { 0.6, 0.3, 0.1 }; a3OT_021.setPro(a3OT_021pro);
	float a3OT_100pro[3] = { 0.6, 0.3, 0.1 }; a3OT_100.setPro(a3OT_100pro);
	float a3OT_101pro[3] = { 0.1, 0.8, 0.1 }; a3OT_101.setPro(a3OT_101pro);
	float a3OT_102pro[3] = { 0.2, 0.7, 0.1 }; a3OT_102.setPro(a3OT_102pro);
	float a3OT_110pro[3] = { 0.5, 0.4, 0.1 }; a3OT_110.setPro(a3OT_110pro);
	float a3OT_111pro[3] = { 0.2, 0.7, 0.1 }; a3OT_111.setPro(a3OT_111pro);
	float a3OT_112pro[3] = { 0.3, 0.6, 0.1 }; a3OT_112.setPro(a3OT_112pro);
	float a3OT_120pro[3] = { 0.6, 0.3, 0.1 }; a3OT_120.setPro(a3OT_120pro);
	float a3OT_121pro[3] = { 0.3, 0.6, 0.1 }; a3OT_121.setPro(a3OT_121pro);
	float a3OT_200pro[3] = { 0.8, 0.1, 0.1 }; a3OT_200.setPro(a3OT_200pro);
	float a3OT_201pro[3] = { 0.1, 0.8, 0.1 }; a3OT_201.setPro(a3OT_201pro);
	float a3OT_210pro[3] = { 0.7, 0.2, 0.1 }; a3OT_210.setPro(a3OT_210pro);
	float a3OT_211pro[3] = { 0.3, 0.6, 0.1 }; a3OT_211.setPro(a3OT_211pro);
	float a3OT_0000pro[3] = { 0.8, 0.1, 0.1 }; a3OT_0000.setPro(a3OT_0000pro);
	float a3OT_0001pro[3] = { 0.1, 0.8, 0.1 }; a3OT_0001.setPro(a3OT_0001pro);
	float a3OT_0002pro[3] = { 0.1, 0.8, 0.1 }; a3OT_0002.setPro(a3OT_0002pro);
	float a3OT_0010pro[3] = { 0.6, 0.2, 0.2 }; a3OT_0010.setPro(a3OT_0010pro);
	float a3OT_0011pro[3] = { 0.7, 0.2, 0.1 }; a3OT_0011.setPro(a3OT_0011pro);
	float a3OT_0012pro[3] = { 0.4, 0.5, 0.1 }; a3OT_0012.setPro(a3OT_0012pro);
	float a3OT_0020pro[3] = { 0.7, 0.2, 0.1 }; a3OT_0020.setPro(a3OT_0020pro);
	float a3OT_0021pro[3] = { 0.6, 0.3, 0.1 }; a3OT_0021.setPro(a3OT_0021pro);
	float a3OT_0100pro[3] = { 0.6, 0.3, 0.1 }; a3OT_0100.setPro(a3OT_0100pro);
	float a3OT_0101pro[3] = { 0.1, 0.8, 0.1 }; a3OT_0101.setPro(a3OT_0101pro);
	float a3OT_0102pro[3] = { 0.2, 0.7, 0.1 }; a3OT_0102.setPro(a3OT_0102pro);
	float a3OT_0110pro[3] = { 0.5, 0.4, 0.1 }; a3OT_0110.setPro(a3OT_0110pro);
	float a3OT_0111pro[3] = { 0.2, 0.7, 0.1 }; a3OT_0111.setPro(a3OT_0111pro);
	float a3OT_0112pro[3] = { 0.3, 0.6, 0.1 }; a3OT_0112.setPro(a3OT_0112pro);
	float a3OT_0120pro[3] = { 0.6, 0.3, 0.1 }; a3OT_0120.setPro(a3OT_0120pro);
	float a3OT_0121pro[3] = { 0.3, 0.6, 0.1 }; a3OT_0121.setPro(a3OT_0121pro);
	float a3OT_0200pro[3] = { 0.8, 0.1, 0.1 }; a3OT_0200.setPro(a3OT_0200pro);
	float a3OT_0201pro[3] = { 0.1, 0.8, 0.1 }; a3OT_0201.setPro(a3OT_0201pro);
	float a3OT_0210pro[3] = { 0.7, 0.2, 0.1 }; a3OT_0210.setPro(a3OT_0210pro);
	float a3OT_0211pro[3] = { 0.3, 0.6, 0.1 }; a3OT_0211.setPro(a3OT_0211pro);
	float a3OT_1000pro[3] = { 0.8, 0.1, 0.1 }; a3OT_1000.setPro(a3OT_1000pro);
	float a3OT_1001pro[3] = { 0.1, 0.8, 0.1 }; a3OT_1001.setPro(a3OT_1001pro);
	float a3OT_1002pro[3] = { 0.1, 0.8, 0.1 }; a3OT_1002.setPro(a3OT_1002pro);
	float a3OT_1010pro[3] = { 0.6, 0.2, 0.2 }; a3OT_1010.setPro(a3OT_1010pro);
	float a3OT_1011pro[3] = { 0.7, 0.2, 0.1 }; a3OT_1011.setPro(a3OT_1011pro);
	float a3OT_1012pro[3] = { 0.4, 0.5, 0.1 }; a3OT_1012.setPro(a3OT_1012pro);
	float a3OT_1020pro[3] = { 0.7, 0.2, 0.1 }; a3OT_1020.setPro(a3OT_1020pro);
	float a3OT_1021pro[3] = { 0.6, 0.3, 0.1 }; a3OT_1021.setPro(a3OT_1021pro);
	float a3OT_1100pro[3] = { 0.6, 0.3, 0.1 }; a3OT_1100.setPro(a3OT_1100pro);
	float a3OT_1101pro[3] = { 0.1, 0.8, 0.1 }; a3OT_1101.setPro(a3OT_1101pro);
	float a3OT_1102pro[3] = { 0.2, 0.7, 0.1 }; a3OT_1102.setPro(a3OT_1102pro);
	float a3OT_1110pro[3] = { 0.5, 0.4, 0.1 }; a3OT_1110.setPro(a3OT_1110pro);
	float a3OT_1111pro[3] = { 0.2, 0.7, 0.1 }; a3OT_1111.setPro(a3OT_1111pro);
	float a3OT_1112pro[3] = { 0.3, 0.6, 0.1 }; a3OT_1112.setPro(a3OT_1112pro);
	float a3OT_1120pro[3] = { 0.6, 0.3, 0.1 }; a3OT_1120.setPro(a3OT_1120pro);
	float a3OT_1121pro[3] = { 0.3, 0.6, 0.1 }; a3OT_1121.setPro(a3OT_1121pro);
	float a3OT_1200pro[3] = { 0.8, 0.1, 0.1 }; a3OT_1200.setPro(a3OT_1200pro);
	float a3OT_1201pro[3] = { 0.1, 0.8, 0.1 }; a3OT_1201.setPro(a3OT_1201pro);
	float a3OT_1210pro[3] = { 0.7, 0.2, 0.1 }; a3OT_1210.setPro(a3OT_1210pro);
	float a3OT_1211pro[3] = { 0.3, 0.6, 0.1 }; a3OT_1211.setPro(a3OT_1211pro);
	float a3OT_2000pro[3] = { 0.8, 0.1, 0.1 }; a3OT_2000.setPro(a3OT_2000pro);
	float a3OT_2001pro[3] = { 0.1, 0.8, 0.1 }; a3OT_2001.setPro(a3OT_2001pro);
	float a3OT_2002pro[3] = { 0.1, 0.8, 0.1 }; a3OT_2002.setPro(a3OT_2002pro);
	float a3OT_2010pro[3] = { 0.6, 0.2, 0.2 }; a3OT_2010.setPro(a3OT_2010pro);
	float a3OT_2011pro[3] = { 0.7, 0.2, 0.1 }; a3OT_2011.setPro(a3OT_2011pro);
	float a3OT_2012pro[3] = { 0.4, 0.5, 0.1 }; a3OT_2012.setPro(a3OT_2012pro);
	float a3OT_2020pro[3] = { 0.7, 0.2, 0.1 }; a3OT_2020.setPro(a3OT_2020pro);
	float a3OT_2021pro[3] = { 0.6, 0.3, 0.1 }; a3OT_2021.setPro(a3OT_2021pro);
	float a3OT_2100pro[3] = { 0.6, 0.3, 0.1 }; a3OT_2100.setPro(a3OT_2100pro);
	float a3OT_2101pro[3] = { 0.1, 0.8, 0.1 }; a3OT_2101.setPro(a3OT_2101pro);
	float a3OT_2102pro[3] = { 0.2, 0.7, 0.1 }; a3OT_2102.setPro(a3OT_2102pro);
	float a3OT_2110pro[3] = { 0.5, 0.4, 0.1 }; a3OT_2110.setPro(a3OT_2110pro);
	float a3OT_2111pro[3] = { 0.2, 0.7, 0.1 }; a3OT_2111.setPro(a3OT_2111pro);
	float a3OT_2112pro[3] = { 0.3, 0.6, 0.1 }; a3OT_2112.setPro(a3OT_2112pro);
	float a3OT_2120pro[3] = { 0.6, 0.3, 0.1 }; a3OT_2120.setPro(a3OT_2120pro);
	float a3OT_2121pro[3] = { 0.3, 0.6, 0.1 }; a3OT_2121.setPro(a3OT_2121pro);
	float a3OT_2200pro[3] = { 0.8, 0.1, 0.1 }; a3OT_2200.setPro(a3OT_2200pro);
	float a3OT_2201pro[3] = { 0.1, 0.8, 0.1 }; a3OT_2201.setPro(a3OT_2201pro);
	float a3OT_2210pro[3] = { 0.7, 0.2, 0.1 }; a3OT_2210.setPro(a3OT_2210pro);
	float a3OT_2211pro[3] = { 0.3, 0.6, 0.1 }; a3OT_2211.setPro(a3OT_2211pro);

    aMSC_L.reset();
    aMSC_A.reset();
    aMSC_B.reset();
    aMSC_R.reset();
    aMSC_I.reset();
    if (num_arr1[0] > 0) { aMSC_0.set_alphabet( num_arr1[0]); aMSC_0.copy( ada_P_arr1[0]); } else aMSC_0.reset();
    if (num_arr1[1] > 0) { aMSC_1.set_alphabet( num_arr1[1]); aMSC_1.copy( ada_P_arr1[1]); } else aMSC_1.reset();
    if (num_arr1[2] > 0) { aMSC_2.set_alphabet( num_arr1[2]); aMSC_2.copy( ada_P_arr1[2]); } else aMSC_2.reset();
    if (num_arr1[3] > 0) { aMSC_3.set_alphabet( num_arr1[3]); aMSC_3.copy( ada_P_arr1[3]); } else aMSC_3.reset();
    if (num_arr1[4] > 0) { aMSC_4.set_alphabet( num_arr1[4]); aMSC_4.copy( ada_P_arr1[4]); } else aMSC_4.reset();
    if (num_arr1[5] > 0) { aMSC_5.set_alphabet( num_arr1[5]); aMSC_5.copy( ada_P_arr1[5]); } else aMSC_5.reset();
    if (num_arr1[6] > 0) { aMSC_6.set_alphabet( num_arr1[6]); aMSC_6.copy( ada_P_arr1[6]); } else aMSC_6.reset();
    if (num_arr1[7] > 0) { aMSC_7.set_alphabet( num_arr1[7]); aMSC_7.copy( ada_P_arr1[7]); } else aMSC_7.reset();
    if (num_arr1[8] > 0) { aMSC_8.set_alphabet( num_arr1[8]); aMSC_8.copy( ada_P_arr1[8]); } else aMSC_8.reset();
    if (num_arr[0][0 ] > 0) { aMSC_00.set_alphabet( num_arr[0][0 ]); aMSC_00.copy( ada_P_arr[0][0 ]); } else aMSC_00.reset();
    if (num_arr[0][1 ] > 0) { aMSC_01.set_alphabet( num_arr[0][1 ]); aMSC_01.copy( ada_P_arr[0][1 ]); } else aMSC_01.reset();
    if (num_arr[0][2 ] > 0) { aMSC_02.set_alphabet( num_arr[0][2 ]); aMSC_02.copy( ada_P_arr[0][2 ]); } else aMSC_02.reset();
    if (num_arr[0][3 ] > 0) { aMSC_03.set_alphabet( num_arr[0][3 ]); aMSC_03.copy( ada_P_arr[0][3 ]); } else aMSC_03.reset();
    if (num_arr[0][4 ] > 0) { aMSC_04.set_alphabet( num_arr[0][4 ]); aMSC_04.copy( ada_P_arr[0][4 ]); } else aMSC_04.reset();
    if (num_arr[0][5 ] > 0) { aMSC_05.set_alphabet( num_arr[0][5 ]); aMSC_05.copy( ada_P_arr[0][5 ]); } else aMSC_05.reset();
    if (num_arr[0][6 ] > 0) { aMSC_06.set_alphabet( num_arr[0][6 ]); aMSC_06.copy( ada_P_arr[0][6 ]); } else aMSC_06.reset();
    if (num_arr[0][7 ] > 0) { aMSC_07.set_alphabet( num_arr[0][7 ]); aMSC_07.copy( ada_P_arr[0][7 ]); } else aMSC_07.reset();
    if (num_arr[0][8 ] > 0) { aMSC_08.set_alphabet( num_arr[0][8 ]); aMSC_08.copy( ada_P_arr[0][8 ]); } else aMSC_08.reset();
    if (num_arr[0][9 ] > 0) { aMSC_09.set_alphabet( num_arr[0][9 ]); aMSC_09.copy( ada_P_arr[0][9 ]); } else aMSC_09.reset();
    if (num_arr[0][10] > 0) { aMSC_010.set_alphabet(num_arr[0][10]); aMSC_010.copy(ada_P_arr[0][10]); } else aMSC_010.reset();
    if (num_arr[0][11] > 0) { aMSC_011.set_alphabet(num_arr[0][11]); aMSC_011.copy(ada_P_arr[0][11]); } else aMSC_011.reset();
    if (num_arr[0][12] > 0) { aMSC_012.set_alphabet(num_arr[0][12]); aMSC_012.copy(ada_P_arr[0][12]); } else aMSC_012.reset();
    if (num_arr[0][13] > 0) { aMSC_013.set_alphabet(num_arr[0][13]); aMSC_013.copy(ada_P_arr[0][13]); } else aMSC_013.reset();
    if (num_arr[0][14] > 0) { aMSC_014.set_alphabet(num_arr[0][14]); aMSC_014.copy(ada_P_arr[0][14]); } else aMSC_014.reset();
    if (num_arr[0][15] > 0) { aMSC_015.set_alphabet(num_arr[0][15]); aMSC_015.copy(ada_P_arr[0][15]); } else aMSC_015.reset();
    if (num_arr[0][16] > 0) { aMSC_016.set_alphabet(num_arr[0][16]); aMSC_016.copy(ada_P_arr[0][16]); } else aMSC_016.reset();
    if (num_arr[0][17] > 0) { aMSC_017.set_alphabet(num_arr[0][17]); aMSC_017.copy(ada_P_arr[0][17]); } else aMSC_017.reset();
    if (num_arr[0][18] > 0) { aMSC_018.set_alphabet(num_arr[0][18]); aMSC_018.copy(ada_P_arr[0][18]); } else aMSC_018.reset();
    if (num_arr[0][19] > 0) { aMSC_019.set_alphabet(num_arr[0][19]); aMSC_019.copy(ada_P_arr[0][19]); } else aMSC_019.reset();
    if (num_arr[0][20] > 0) { aMSC_020.set_alphabet(num_arr[0][20]); aMSC_020.copy(ada_P_arr[0][20]); } else aMSC_020.reset();
    if (num_arr[0][21] > 0) { aMSC_021.set_alphabet(num_arr[0][21]); aMSC_021.copy(ada_P_arr[0][21]); } else aMSC_021.reset();
    if (num_arr[0][22] > 0) { aMSC_022.set_alphabet(num_arr[0][22]); aMSC_022.copy(ada_P_arr[0][22]); } else aMSC_022.reset();
    if (num_arr[0][23] > 0) { aMSC_023.set_alphabet(num_arr[0][23]); aMSC_023.copy(ada_P_arr[0][23]); } else aMSC_023.reset();
    if (num_arr[0][24] > 0) { aMSC_024.set_alphabet(num_arr[0][24]); aMSC_024.copy(ada_P_arr[0][24]); } else aMSC_024.reset();
    if (num_arr[0][25] > 0) { aMSC_025.set_alphabet(num_arr[0][25]); aMSC_025.copy(ada_P_arr[0][25]); } else aMSC_025.reset();
    if (num_arr[0][26] > 0) { aMSC_026.set_alphabet(num_arr[0][26]); aMSC_026.copy(ada_P_arr[0][26]); } else aMSC_026.reset();
    if (num_arr[1][0 ] > 0) { aMSC_10.set_alphabet( num_arr[1][0 ]); aMSC_10.copy( ada_P_arr[1][0 ]); } else aMSC_10.reset();
    if (num_arr[1][1 ] > 0) { aMSC_11.set_alphabet( num_arr[1][1 ]); aMSC_11.copy( ada_P_arr[1][1 ]); } else aMSC_11.reset();
    if (num_arr[1][2 ] > 0) { aMSC_12.set_alphabet( num_arr[1][2 ]); aMSC_12.copy( ada_P_arr[1][2 ]); } else aMSC_12.reset();
    if (num_arr[1][3 ] > 0) { aMSC_13.set_alphabet( num_arr[1][3 ]); aMSC_13.copy( ada_P_arr[1][3 ]); } else aMSC_13.reset();
    if (num_arr[1][4 ] > 0) { aMSC_14.set_alphabet( num_arr[1][4 ]); aMSC_14.copy( ada_P_arr[1][4 ]); } else aMSC_14.reset();
    if (num_arr[1][5 ] > 0) { aMSC_15.set_alphabet( num_arr[1][5 ]); aMSC_15.copy( ada_P_arr[1][5 ]); } else aMSC_15.reset();
    if (num_arr[1][6 ] > 0) { aMSC_16.set_alphabet( num_arr[1][6 ]); aMSC_16.copy( ada_P_arr[1][6 ]); } else aMSC_16.reset();
    if (num_arr[1][7 ] > 0) { aMSC_17.set_alphabet( num_arr[1][7 ]); aMSC_17.copy( ada_P_arr[1][7 ]); } else aMSC_17.reset();
    if (num_arr[1][8 ] > 0) { aMSC_18.set_alphabet( num_arr[1][8 ]); aMSC_18.copy( ada_P_arr[1][8 ]); } else aMSC_18.reset();
    if (num_arr[1][9 ] > 0) { aMSC_19.set_alphabet( num_arr[1][9 ]); aMSC_19.copy( ada_P_arr[1][9 ]); } else aMSC_19.reset();
    if (num_arr[1][10] > 0) { aMSC_110.set_alphabet(num_arr[1][10]); aMSC_110.copy(ada_P_arr[1][10]); } else aMSC_110.reset();
    if (num_arr[1][11] > 0) { aMSC_111.set_alphabet(num_arr[1][11]); aMSC_111.copy(ada_P_arr[1][11]); } else aMSC_111.reset();
    if (num_arr[1][12] > 0) { aMSC_112.set_alphabet(num_arr[1][12]); aMSC_112.copy(ada_P_arr[1][12]); } else aMSC_112.reset();
    if (num_arr[1][13] > 0) { aMSC_113.set_alphabet(num_arr[1][13]); aMSC_113.copy(ada_P_arr[1][13]); } else aMSC_113.reset();
    if (num_arr[1][14] > 0) { aMSC_114.set_alphabet(num_arr[1][14]); aMSC_114.copy(ada_P_arr[1][14]); } else aMSC_114.reset();
    if (num_arr[1][15] > 0) { aMSC_115.set_alphabet(num_arr[1][15]); aMSC_115.copy(ada_P_arr[1][15]); } else aMSC_115.reset();
    if (num_arr[1][16] > 0) { aMSC_116.set_alphabet(num_arr[1][16]); aMSC_116.copy(ada_P_arr[1][16]); } else aMSC_116.reset();
    if (num_arr[1][17] > 0) { aMSC_117.set_alphabet(num_arr[1][17]); aMSC_117.copy(ada_P_arr[1][17]); } else aMSC_117.reset();
    if (num_arr[1][18] > 0) { aMSC_118.set_alphabet(num_arr[1][18]); aMSC_118.copy(ada_P_arr[1][18]); } else aMSC_118.reset();
    if (num_arr[1][19] > 0) { aMSC_119.set_alphabet(num_arr[1][19]); aMSC_119.copy(ada_P_arr[1][19]); } else aMSC_119.reset();
    if (num_arr[1][20] > 0) { aMSC_120.set_alphabet(num_arr[1][20]); aMSC_120.copy(ada_P_arr[1][20]); } else aMSC_120.reset();
    if (num_arr[1][21] > 0) { aMSC_121.set_alphabet(num_arr[1][21]); aMSC_121.copy(ada_P_arr[1][21]); } else aMSC_121.reset();
    if (num_arr[1][22] > 0) { aMSC_122.set_alphabet(num_arr[1][22]); aMSC_122.copy(ada_P_arr[1][22]); } else aMSC_122.reset();
    if (num_arr[1][23] > 0) { aMSC_123.set_alphabet(num_arr[1][23]); aMSC_123.copy(ada_P_arr[1][23]); } else aMSC_123.reset();
    if (num_arr[1][24] > 0) { aMSC_124.set_alphabet(num_arr[1][24]); aMSC_124.copy(ada_P_arr[1][24]); } else aMSC_124.reset();
    if (num_arr[1][25] > 0) { aMSC_125.set_alphabet(num_arr[1][25]); aMSC_125.copy(ada_P_arr[1][25]); } else aMSC_125.reset();
    if (num_arr[1][26] > 0) { aMSC_126.set_alphabet(num_arr[1][26]); aMSC_126.copy(ada_P_arr[1][26]); } else aMSC_126.reset();
    if (num_arr[2][0 ] > 0) { aMSC_20.set_alphabet( num_arr[2][0 ]); aMSC_20.copy( ada_P_arr[2][0 ]); } else aMSC_20.reset();
    if (num_arr[2][1 ] > 0) { aMSC_21.set_alphabet( num_arr[2][1 ]); aMSC_21.copy( ada_P_arr[2][1 ]); } else aMSC_21.reset();
    if (num_arr[2][2 ] > 0) { aMSC_22.set_alphabet( num_arr[2][2 ]); aMSC_22.copy( ada_P_arr[2][2 ]); } else aMSC_22.reset();
    if (num_arr[2][3 ] > 0) { aMSC_23.set_alphabet( num_arr[2][3 ]); aMSC_23.copy( ada_P_arr[2][3 ]); } else aMSC_23.reset();
    if (num_arr[2][4 ] > 0) { aMSC_24.set_alphabet( num_arr[2][4 ]); aMSC_24.copy( ada_P_arr[2][4 ]); } else aMSC_24.reset();
    if (num_arr[2][5 ] > 0) { aMSC_25.set_alphabet( num_arr[2][5 ]); aMSC_25.copy( ada_P_arr[2][5 ]); } else aMSC_25.reset();
    if (num_arr[2][6 ] > 0) { aMSC_26.set_alphabet( num_arr[2][6 ]); aMSC_26.copy( ada_P_arr[2][6 ]); } else aMSC_26.reset();
    if (num_arr[2][7 ] > 0) { aMSC_27.set_alphabet( num_arr[2][7 ]); aMSC_27.copy( ada_P_arr[2][7 ]); } else aMSC_27.reset();
    if (num_arr[2][8 ] > 0) { aMSC_28.set_alphabet( num_arr[2][8 ]); aMSC_28.copy( ada_P_arr[2][8 ]); } else aMSC_28.reset();
    if (num_arr[2][9 ] > 0) { aMSC_29.set_alphabet( num_arr[2][9 ]); aMSC_29.copy( ada_P_arr[2][9 ]); } else aMSC_29.reset();
    if (num_arr[2][10] > 0) { aMSC_210.set_alphabet(num_arr[2][10]); aMSC_210.copy(ada_P_arr[2][10]); } else aMSC_210.reset();
    if (num_arr[2][11] > 0) { aMSC_211.set_alphabet(num_arr[2][11]); aMSC_211.copy(ada_P_arr[2][11]); } else aMSC_211.reset();
    if (num_arr[2][12] > 0) { aMSC_212.set_alphabet(num_arr[2][12]); aMSC_212.copy(ada_P_arr[2][12]); } else aMSC_212.reset();
    if (num_arr[2][13] > 0) { aMSC_213.set_alphabet(num_arr[2][13]); aMSC_213.copy(ada_P_arr[2][13]); } else aMSC_213.reset();
    if (num_arr[2][14] > 0) { aMSC_214.set_alphabet(num_arr[2][14]); aMSC_214.copy(ada_P_arr[2][14]); } else aMSC_214.reset();
    if (num_arr[2][15] > 0) { aMSC_215.set_alphabet(num_arr[2][15]); aMSC_215.copy(ada_P_arr[2][15]); } else aMSC_215.reset();
    if (num_arr[2][16] > 0) { aMSC_216.set_alphabet(num_arr[2][16]); aMSC_216.copy(ada_P_arr[2][16]); } else aMSC_216.reset();
    if (num_arr[2][17] > 0) { aMSC_217.set_alphabet(num_arr[2][17]); aMSC_217.copy(ada_P_arr[2][17]); } else aMSC_217.reset();
    if (num_arr[2][18] > 0) { aMSC_218.set_alphabet(num_arr[2][18]); aMSC_218.copy(ada_P_arr[2][18]); } else aMSC_218.reset();
    if (num_arr[2][19] > 0) { aMSC_219.set_alphabet(num_arr[2][19]); aMSC_219.copy(ada_P_arr[2][19]); } else aMSC_219.reset();
    if (num_arr[2][20] > 0) { aMSC_220.set_alphabet(num_arr[2][20]); aMSC_220.copy(ada_P_arr[2][20]); } else aMSC_220.reset();
    if (num_arr[2][21] > 0) { aMSC_221.set_alphabet(num_arr[2][21]); aMSC_221.copy(ada_P_arr[2][21]); } else aMSC_221.reset();
    if (num_arr[2][22] > 0) { aMSC_222.set_alphabet(num_arr[2][22]); aMSC_222.copy(ada_P_arr[2][22]); } else aMSC_222.reset();
    if (num_arr[2][23] > 0) { aMSC_223.set_alphabet(num_arr[2][23]); aMSC_223.copy(ada_P_arr[2][23]); } else aMSC_223.reset();
    if (num_arr[2][24] > 0) { aMSC_224.set_alphabet(num_arr[2][24]); aMSC_224.copy(ada_P_arr[2][24]); } else aMSC_224.reset();
    if (num_arr[2][25] > 0) { aMSC_225.set_alphabet(num_arr[2][25]); aMSC_225.copy(ada_P_arr[2][25]); } else aMSC_225.reset();
    if (num_arr[2][26] > 0) { aMSC_226.set_alphabet(num_arr[2][26]); aMSC_226.copy(ada_P_arr[2][26]); } else aMSC_226.reset();
    if (num_arr[3][0 ] > 0) { aMSC_30.set_alphabet( num_arr[3][0 ]); aMSC_30.copy( ada_P_arr[3][0 ]); } else aMSC_30.reset();
    if (num_arr[3][1 ] > 0) { aMSC_31.set_alphabet( num_arr[3][1 ]); aMSC_31.copy( ada_P_arr[3][1 ]); } else aMSC_31.reset();
    if (num_arr[3][2 ] > 0) { aMSC_32.set_alphabet( num_arr[3][2 ]); aMSC_32.copy( ada_P_arr[3][2 ]); } else aMSC_32.reset();
    if (num_arr[3][3 ] > 0) { aMSC_33.set_alphabet( num_arr[3][3 ]); aMSC_33.copy( ada_P_arr[3][3 ]); } else aMSC_33.reset();
    if (num_arr[3][4 ] > 0) { aMSC_34.set_alphabet( num_arr[3][4 ]); aMSC_34.copy( ada_P_arr[3][4 ]); } else aMSC_34.reset();
    if (num_arr[3][5 ] > 0) { aMSC_35.set_alphabet( num_arr[3][5 ]); aMSC_35.copy( ada_P_arr[3][5 ]); } else aMSC_35.reset();
    if (num_arr[3][6 ] > 0) { aMSC_36.set_alphabet( num_arr[3][6 ]); aMSC_36.copy( ada_P_arr[3][6 ]); } else aMSC_36.reset();
    if (num_arr[3][7 ] > 0) { aMSC_37.set_alphabet( num_arr[3][7 ]); aMSC_37.copy( ada_P_arr[3][7 ]); } else aMSC_37.reset();
    if (num_arr[3][8 ] > 0) { aMSC_38.set_alphabet( num_arr[3][8 ]); aMSC_38.copy( ada_P_arr[3][8 ]); } else aMSC_38.reset();
    if (num_arr[3][9 ] > 0) { aMSC_39.set_alphabet( num_arr[3][9 ]); aMSC_39.copy( ada_P_arr[3][9 ]); } else aMSC_39.reset();
    if (num_arr[3][10] > 0) { aMSC_310.set_alphabet(num_arr[3][10]); aMSC_310.copy(ada_P_arr[3][10]); } else aMSC_310.reset();
    if (num_arr[3][11] > 0) { aMSC_311.set_alphabet(num_arr[3][11]); aMSC_311.copy(ada_P_arr[3][11]); } else aMSC_311.reset();
    if (num_arr[3][12] > 0) { aMSC_312.set_alphabet(num_arr[3][12]); aMSC_312.copy(ada_P_arr[3][12]); } else aMSC_312.reset();
    if (num_arr[3][13] > 0) { aMSC_313.set_alphabet(num_arr[3][13]); aMSC_313.copy(ada_P_arr[3][13]); } else aMSC_313.reset();
    if (num_arr[3][14] > 0) { aMSC_314.set_alphabet(num_arr[3][14]); aMSC_314.copy(ada_P_arr[3][14]); } else aMSC_314.reset();
    if (num_arr[3][15] > 0) { aMSC_315.set_alphabet(num_arr[3][15]); aMSC_315.copy(ada_P_arr[3][15]); } else aMSC_315.reset();
    if (num_arr[3][16] > 0) { aMSC_316.set_alphabet(num_arr[3][16]); aMSC_316.copy(ada_P_arr[3][16]); } else aMSC_316.reset();
    if (num_arr[3][17] > 0) { aMSC_317.set_alphabet(num_arr[3][17]); aMSC_317.copy(ada_P_arr[3][17]); } else aMSC_317.reset();
    if (num_arr[3][18] > 0) { aMSC_318.set_alphabet(num_arr[3][18]); aMSC_318.copy(ada_P_arr[3][18]); } else aMSC_318.reset();
    if (num_arr[3][19] > 0) { aMSC_319.set_alphabet(num_arr[3][19]); aMSC_319.copy(ada_P_arr[3][19]); } else aMSC_319.reset();
    if (num_arr[3][20] > 0) { aMSC_320.set_alphabet(num_arr[3][20]); aMSC_320.copy(ada_P_arr[3][20]); } else aMSC_320.reset();
    if (num_arr[3][21] > 0) { aMSC_321.set_alphabet(num_arr[3][21]); aMSC_321.copy(ada_P_arr[3][21]); } else aMSC_321.reset();
    if (num_arr[3][22] > 0) { aMSC_322.set_alphabet(num_arr[3][22]); aMSC_322.copy(ada_P_arr[3][22]); } else aMSC_322.reset();
    if (num_arr[3][23] > 0) { aMSC_323.set_alphabet(num_arr[3][23]); aMSC_323.copy(ada_P_arr[3][23]); } else aMSC_323.reset();
    if (num_arr[3][24] > 0) { aMSC_324.set_alphabet(num_arr[3][24]); aMSC_324.copy(ada_P_arr[3][24]); } else aMSC_324.reset();
    if (num_arr[3][25] > 0) { aMSC_325.set_alphabet(num_arr[3][25]); aMSC_325.copy(ada_P_arr[3][25]); } else aMSC_325.reset();
    if (num_arr[3][26] > 0) { aMSC_326.set_alphabet(num_arr[3][26]); aMSC_326.copy(ada_P_arr[3][26]); } else aMSC_326.reset();
    if (num_arr[4][0 ] > 0) { aMSC_40.set_alphabet( num_arr[4][0 ]); aMSC_40.copy( ada_P_arr[4][0 ]); } else aMSC_40.reset();
    if (num_arr[4][1 ] > 0) { aMSC_41.set_alphabet( num_arr[4][1 ]); aMSC_41.copy( ada_P_arr[4][1 ]); } else aMSC_41.reset();
    if (num_arr[4][2 ] > 0) { aMSC_42.set_alphabet( num_arr[4][2 ]); aMSC_42.copy( ada_P_arr[4][2 ]); } else aMSC_42.reset();
    if (num_arr[4][3 ] > 0) { aMSC_43.set_alphabet( num_arr[4][3 ]); aMSC_43.copy( ada_P_arr[4][3 ]); } else aMSC_43.reset();
    if (num_arr[4][4 ] > 0) { aMSC_44.set_alphabet( num_arr[4][4 ]); aMSC_44.copy( ada_P_arr[4][4 ]); } else aMSC_44.reset();
    if (num_arr[4][5 ] > 0) { aMSC_45.set_alphabet( num_arr[4][5 ]); aMSC_45.copy( ada_P_arr[4][5 ]); } else aMSC_45.reset();
    if (num_arr[4][6 ] > 0) { aMSC_46.set_alphabet( num_arr[4][6 ]); aMSC_46.copy( ada_P_arr[4][6 ]); } else aMSC_46.reset();
    if (num_arr[4][7 ] > 0) { aMSC_47.set_alphabet( num_arr[4][7 ]); aMSC_47.copy( ada_P_arr[4][7 ]); } else aMSC_47.reset();
    if (num_arr[4][8 ] > 0) { aMSC_48.set_alphabet( num_arr[4][8 ]); aMSC_48.copy( ada_P_arr[4][8 ]); } else aMSC_48.reset();
    if (num_arr[4][9 ] > 0) { aMSC_49.set_alphabet( num_arr[4][9 ]); aMSC_49.copy( ada_P_arr[4][9 ]); } else aMSC_49.reset();
    if (num_arr[4][10] > 0) { aMSC_410.set_alphabet(num_arr[4][10]); aMSC_410.copy(ada_P_arr[4][10]); } else aMSC_410.reset();
    if (num_arr[4][11] > 0) { aMSC_411.set_alphabet(num_arr[4][11]); aMSC_411.copy(ada_P_arr[4][11]); } else aMSC_411.reset();
    if (num_arr[4][12] > 0) { aMSC_412.set_alphabet(num_arr[4][12]); aMSC_412.copy(ada_P_arr[4][12]); } else aMSC_412.reset();
    if (num_arr[4][13] > 0) { aMSC_413.set_alphabet(num_arr[4][13]); aMSC_413.copy(ada_P_arr[4][13]); } else aMSC_413.reset();
    if (num_arr[4][14] > 0) { aMSC_414.set_alphabet(num_arr[4][14]); aMSC_414.copy(ada_P_arr[4][14]); } else aMSC_414.reset();
    if (num_arr[4][15] > 0) { aMSC_415.set_alphabet(num_arr[4][15]); aMSC_415.copy(ada_P_arr[4][15]); } else aMSC_415.reset();
    if (num_arr[4][16] > 0) { aMSC_416.set_alphabet(num_arr[4][16]); aMSC_416.copy(ada_P_arr[4][16]); } else aMSC_416.reset();
    if (num_arr[4][17] > 0) { aMSC_417.set_alphabet(num_arr[4][17]); aMSC_417.copy(ada_P_arr[4][17]); } else aMSC_417.reset();
    if (num_arr[4][18] > 0) { aMSC_418.set_alphabet(num_arr[4][18]); aMSC_418.copy(ada_P_arr[4][18]); } else aMSC_418.reset();
    if (num_arr[4][19] > 0) { aMSC_419.set_alphabet(num_arr[4][19]); aMSC_419.copy(ada_P_arr[4][19]); } else aMSC_419.reset();
    if (num_arr[4][20] > 0) { aMSC_420.set_alphabet(num_arr[4][20]); aMSC_420.copy(ada_P_arr[4][20]); } else aMSC_420.reset();
    if (num_arr[4][21] > 0) { aMSC_421.set_alphabet(num_arr[4][21]); aMSC_421.copy(ada_P_arr[4][21]); } else aMSC_421.reset();
    if (num_arr[4][22] > 0) { aMSC_422.set_alphabet(num_arr[4][22]); aMSC_422.copy(ada_P_arr[4][22]); } else aMSC_422.reset();
    if (num_arr[4][23] > 0) { aMSC_423.set_alphabet(num_arr[4][23]); aMSC_423.copy(ada_P_arr[4][23]); } else aMSC_423.reset();
    if (num_arr[4][24] > 0) { aMSC_424.set_alphabet(num_arr[4][24]); aMSC_424.copy(ada_P_arr[4][24]); } else aMSC_424.reset();
    if (num_arr[4][25] > 0) { aMSC_425.set_alphabet(num_arr[4][25]); aMSC_425.copy(ada_P_arr[4][25]); } else aMSC_425.reset();
    if (num_arr[4][26] > 0) { aMSC_426.set_alphabet(num_arr[4][26]); aMSC_426.copy(ada_P_arr[4][26]); } else aMSC_426.reset();
    if (num_arr[5][0 ] > 0) { aMSC_50.set_alphabet( num_arr[5][0 ]); aMSC_50.copy( ada_P_arr[5][0 ]); } else aMSC_50.reset();
    if (num_arr[5][1 ] > 0) { aMSC_51.set_alphabet( num_arr[5][1 ]); aMSC_51.copy( ada_P_arr[5][1 ]); } else aMSC_51.reset();
    if (num_arr[5][2 ] > 0) { aMSC_52.set_alphabet( num_arr[5][2 ]); aMSC_52.copy( ada_P_arr[5][2 ]); } else aMSC_52.reset();
    if (num_arr[5][3 ] > 0) { aMSC_53.set_alphabet( num_arr[5][3 ]); aMSC_53.copy( ada_P_arr[5][3 ]); } else aMSC_53.reset();
    if (num_arr[5][4 ] > 0) { aMSC_54.set_alphabet( num_arr[5][4 ]); aMSC_54.copy( ada_P_arr[5][4 ]); } else aMSC_54.reset();
    if (num_arr[5][5 ] > 0) { aMSC_55.set_alphabet( num_arr[5][5 ]); aMSC_55.copy( ada_P_arr[5][5 ]); } else aMSC_55.reset();
    if (num_arr[5][6 ] > 0) { aMSC_56.set_alphabet( num_arr[5][6 ]); aMSC_56.copy( ada_P_arr[5][6 ]); } else aMSC_56.reset();
    if (num_arr[5][7 ] > 0) { aMSC_57.set_alphabet( num_arr[5][7 ]); aMSC_57.copy( ada_P_arr[5][7 ]); } else aMSC_57.reset();
    if (num_arr[5][8 ] > 0) { aMSC_58.set_alphabet( num_arr[5][8 ]); aMSC_58.copy( ada_P_arr[5][8 ]); } else aMSC_58.reset();
    if (num_arr[5][9 ] > 0) { aMSC_59.set_alphabet( num_arr[5][9 ]); aMSC_59.copy( ada_P_arr[5][9 ]); } else aMSC_59.reset();
    if (num_arr[5][10] > 0) { aMSC_510.set_alphabet(num_arr[5][10]); aMSC_510.copy(ada_P_arr[5][10]); } else aMSC_510.reset();
    if (num_arr[5][11] > 0) { aMSC_511.set_alphabet(num_arr[5][11]); aMSC_511.copy(ada_P_arr[5][11]); } else aMSC_511.reset();
    if (num_arr[5][12] > 0) { aMSC_512.set_alphabet(num_arr[5][12]); aMSC_512.copy(ada_P_arr[5][12]); } else aMSC_512.reset();
    if (num_arr[5][13] > 0) { aMSC_513.set_alphabet(num_arr[5][13]); aMSC_513.copy(ada_P_arr[5][13]); } else aMSC_513.reset();
    if (num_arr[5][14] > 0) { aMSC_514.set_alphabet(num_arr[5][14]); aMSC_514.copy(ada_P_arr[5][14]); } else aMSC_514.reset();
    if (num_arr[5][15] > 0) { aMSC_515.set_alphabet(num_arr[5][15]); aMSC_515.copy(ada_P_arr[5][15]); } else aMSC_515.reset();
    if (num_arr[5][16] > 0) { aMSC_516.set_alphabet(num_arr[5][16]); aMSC_516.copy(ada_P_arr[5][16]); } else aMSC_516.reset();
    if (num_arr[5][17] > 0) { aMSC_517.set_alphabet(num_arr[5][17]); aMSC_517.copy(ada_P_arr[5][17]); } else aMSC_517.reset();
    if (num_arr[5][18] > 0) { aMSC_518.set_alphabet(num_arr[5][18]); aMSC_518.copy(ada_P_arr[5][18]); } else aMSC_518.reset();
    if (num_arr[5][19] > 0) { aMSC_519.set_alphabet(num_arr[5][19]); aMSC_519.copy(ada_P_arr[5][19]); } else aMSC_519.reset();
    if (num_arr[5][20] > 0) { aMSC_520.set_alphabet(num_arr[5][20]); aMSC_520.copy(ada_P_arr[5][20]); } else aMSC_520.reset();
    if (num_arr[5][21] > 0) { aMSC_521.set_alphabet(num_arr[5][21]); aMSC_521.copy(ada_P_arr[5][21]); } else aMSC_521.reset();
    if (num_arr[5][22] > 0) { aMSC_522.set_alphabet(num_arr[5][22]); aMSC_522.copy(ada_P_arr[5][22]); } else aMSC_522.reset();
    if (num_arr[5][23] > 0) { aMSC_523.set_alphabet(num_arr[5][23]); aMSC_523.copy(ada_P_arr[5][23]); } else aMSC_523.reset();
    if (num_arr[5][24] > 0) { aMSC_524.set_alphabet(num_arr[5][24]); aMSC_524.copy(ada_P_arr[5][24]); } else aMSC_524.reset();
    if (num_arr[5][25] > 0) { aMSC_525.set_alphabet(num_arr[5][25]); aMSC_525.copy(ada_P_arr[5][25]); } else aMSC_525.reset();
    if (num_arr[5][26] > 0) { aMSC_526.set_alphabet(num_arr[5][26]); aMSC_526.copy(ada_P_arr[5][26]); } else aMSC_526.reset();
    if (num_arr[6][0 ] > 0) { aMSC_60.set_alphabet( num_arr[6][0 ]); aMSC_60.copy( ada_P_arr[6][0 ]); } else aMSC_60.reset();
    if (num_arr[6][1 ] > 0) { aMSC_61.set_alphabet( num_arr[6][1 ]); aMSC_61.copy( ada_P_arr[6][1 ]); } else aMSC_61.reset();
    if (num_arr[6][2 ] > 0) { aMSC_62.set_alphabet( num_arr[6][2 ]); aMSC_62.copy( ada_P_arr[6][2 ]); } else aMSC_62.reset();
    if (num_arr[6][3 ] > 0) { aMSC_63.set_alphabet( num_arr[6][3 ]); aMSC_63.copy( ada_P_arr[6][3 ]); } else aMSC_63.reset();
    if (num_arr[6][4 ] > 0) { aMSC_64.set_alphabet( num_arr[6][4 ]); aMSC_64.copy( ada_P_arr[6][4 ]); } else aMSC_64.reset();
    if (num_arr[6][5 ] > 0) { aMSC_65.set_alphabet( num_arr[6][5 ]); aMSC_65.copy( ada_P_arr[6][5 ]); } else aMSC_65.reset();
    if (num_arr[6][6 ] > 0) { aMSC_66.set_alphabet( num_arr[6][6 ]); aMSC_66.copy( ada_P_arr[6][6 ]); } else aMSC_66.reset();
    if (num_arr[6][7 ] > 0) { aMSC_67.set_alphabet( num_arr[6][7 ]); aMSC_67.copy( ada_P_arr[6][7 ]); } else aMSC_67.reset();
    if (num_arr[6][8 ] > 0) { aMSC_68.set_alphabet( num_arr[6][8 ]); aMSC_68.copy( ada_P_arr[6][8 ]); } else aMSC_68.reset();
    if (num_arr[6][9 ] > 0) { aMSC_69.set_alphabet( num_arr[6][9 ]); aMSC_69.copy( ada_P_arr[6][9 ]); } else aMSC_69.reset();
    if (num_arr[6][10] > 0) { aMSC_610.set_alphabet(num_arr[6][10]); aMSC_610.copy(ada_P_arr[6][10]); } else aMSC_610.reset();
    if (num_arr[6][11] > 0) { aMSC_611.set_alphabet(num_arr[6][11]); aMSC_611.copy(ada_P_arr[6][11]); } else aMSC_611.reset();
    if (num_arr[6][12] > 0) { aMSC_612.set_alphabet(num_arr[6][12]); aMSC_612.copy(ada_P_arr[6][12]); } else aMSC_612.reset();
    if (num_arr[6][13] > 0) { aMSC_613.set_alphabet(num_arr[6][13]); aMSC_613.copy(ada_P_arr[6][13]); } else aMSC_613.reset();
    if (num_arr[6][14] > 0) { aMSC_614.set_alphabet(num_arr[6][14]); aMSC_614.copy(ada_P_arr[6][14]); } else aMSC_614.reset();
    if (num_arr[6][15] > 0) { aMSC_615.set_alphabet(num_arr[6][15]); aMSC_615.copy(ada_P_arr[6][15]); } else aMSC_615.reset();
    if (num_arr[6][16] > 0) { aMSC_616.set_alphabet(num_arr[6][16]); aMSC_616.copy(ada_P_arr[6][16]); } else aMSC_616.reset();
    if (num_arr[6][17] > 0) { aMSC_617.set_alphabet(num_arr[6][17]); aMSC_617.copy(ada_P_arr[6][17]); } else aMSC_617.reset();
    if (num_arr[6][18] > 0) { aMSC_618.set_alphabet(num_arr[6][18]); aMSC_618.copy(ada_P_arr[6][18]); } else aMSC_618.reset();
    if (num_arr[6][19] > 0) { aMSC_619.set_alphabet(num_arr[6][19]); aMSC_619.copy(ada_P_arr[6][19]); } else aMSC_619.reset();
    if (num_arr[6][20] > 0) { aMSC_620.set_alphabet(num_arr[6][20]); aMSC_620.copy(ada_P_arr[6][20]); } else aMSC_620.reset();
    if (num_arr[6][21] > 0) { aMSC_621.set_alphabet(num_arr[6][21]); aMSC_621.copy(ada_P_arr[6][21]); } else aMSC_621.reset();
    if (num_arr[6][22] > 0) { aMSC_622.set_alphabet(num_arr[6][22]); aMSC_622.copy(ada_P_arr[6][22]); } else aMSC_622.reset();
    if (num_arr[6][23] > 0) { aMSC_623.set_alphabet(num_arr[6][23]); aMSC_623.copy(ada_P_arr[6][23]); } else aMSC_623.reset();
    if (num_arr[6][24] > 0) { aMSC_624.set_alphabet(num_arr[6][24]); aMSC_624.copy(ada_P_arr[6][24]); } else aMSC_624.reset();
    if (num_arr[6][25] > 0) { aMSC_625.set_alphabet(num_arr[6][25]); aMSC_625.copy(ada_P_arr[6][25]); } else aMSC_625.reset();
    if (num_arr[6][26] > 0) { aMSC_626.set_alphabet(num_arr[6][26]); aMSC_626.copy(ada_P_arr[6][26]); } else aMSC_626.reset();
    if (num_arr[7][0 ] > 0) { aMSC_70.set_alphabet( num_arr[7][0 ]); aMSC_70.copy( ada_P_arr[7][0 ]); } else aMSC_70.reset();
    if (num_arr[7][1 ] > 0) { aMSC_71.set_alphabet( num_arr[7][1 ]); aMSC_71.copy( ada_P_arr[7][1 ]); } else aMSC_71.reset();
    if (num_arr[7][2 ] > 0) { aMSC_72.set_alphabet( num_arr[7][2 ]); aMSC_72.copy( ada_P_arr[7][2 ]); } else aMSC_72.reset();
    if (num_arr[7][3 ] > 0) { aMSC_73.set_alphabet( num_arr[7][3 ]); aMSC_73.copy( ada_P_arr[7][3 ]); } else aMSC_73.reset();
    if (num_arr[7][4 ] > 0) { aMSC_74.set_alphabet( num_arr[7][4 ]); aMSC_74.copy( ada_P_arr[7][4 ]); } else aMSC_74.reset();
    if (num_arr[7][5 ] > 0) { aMSC_75.set_alphabet( num_arr[7][5 ]); aMSC_75.copy( ada_P_arr[7][5 ]); } else aMSC_75.reset();
    if (num_arr[7][6 ] > 0) { aMSC_76.set_alphabet( num_arr[7][6 ]); aMSC_76.copy( ada_P_arr[7][6 ]); } else aMSC_76.reset();
    if (num_arr[7][7 ] > 0) { aMSC_77.set_alphabet( num_arr[7][7 ]); aMSC_77.copy( ada_P_arr[7][7 ]); } else aMSC_77.reset();
    if (num_arr[7][8 ] > 0) { aMSC_78.set_alphabet( num_arr[7][8 ]); aMSC_78.copy( ada_P_arr[7][8 ]); } else aMSC_78.reset();
    if (num_arr[7][9 ] > 0) { aMSC_79.set_alphabet( num_arr[7][9 ]); aMSC_79.copy( ada_P_arr[7][9 ]); } else aMSC_79.reset();
    if (num_arr[7][10] > 0) { aMSC_710.set_alphabet(num_arr[7][10]); aMSC_710.copy(ada_P_arr[7][10]); } else aMSC_710.reset();
    if (num_arr[7][11] > 0) { aMSC_711.set_alphabet(num_arr[7][11]); aMSC_711.copy(ada_P_arr[7][11]); } else aMSC_711.reset();
    if (num_arr[7][12] > 0) { aMSC_712.set_alphabet(num_arr[7][12]); aMSC_712.copy(ada_P_arr[7][12]); } else aMSC_712.reset();
    if (num_arr[7][13] > 0) { aMSC_713.set_alphabet(num_arr[7][13]); aMSC_713.copy(ada_P_arr[7][13]); } else aMSC_713.reset();
    if (num_arr[7][14] > 0) { aMSC_714.set_alphabet(num_arr[7][14]); aMSC_714.copy(ada_P_arr[7][14]); } else aMSC_714.reset();
    if (num_arr[7][15] > 0) { aMSC_715.set_alphabet(num_arr[7][15]); aMSC_715.copy(ada_P_arr[7][15]); } else aMSC_715.reset();
    if (num_arr[7][16] > 0) { aMSC_716.set_alphabet(num_arr[7][16]); aMSC_716.copy(ada_P_arr[7][16]); } else aMSC_716.reset();
    if (num_arr[7][17] > 0) { aMSC_717.set_alphabet(num_arr[7][17]); aMSC_717.copy(ada_P_arr[7][17]); } else aMSC_717.reset();
    if (num_arr[7][18] > 0) { aMSC_718.set_alphabet(num_arr[7][18]); aMSC_718.copy(ada_P_arr[7][18]); } else aMSC_718.reset();
    if (num_arr[7][19] > 0) { aMSC_719.set_alphabet(num_arr[7][19]); aMSC_719.copy(ada_P_arr[7][19]); } else aMSC_719.reset();
    if (num_arr[7][20] > 0) { aMSC_720.set_alphabet(num_arr[7][20]); aMSC_720.copy(ada_P_arr[7][20]); } else aMSC_720.reset();
    if (num_arr[7][21] > 0) { aMSC_721.set_alphabet(num_arr[7][21]); aMSC_721.copy(ada_P_arr[7][21]); } else aMSC_721.reset();
    if (num_arr[7][22] > 0) { aMSC_722.set_alphabet(num_arr[7][22]); aMSC_722.copy(ada_P_arr[7][22]); } else aMSC_722.reset();
    if (num_arr[7][23] > 0) { aMSC_723.set_alphabet(num_arr[7][23]); aMSC_723.copy(ada_P_arr[7][23]); } else aMSC_723.reset();
    if (num_arr[7][24] > 0) { aMSC_724.set_alphabet(num_arr[7][24]); aMSC_724.copy(ada_P_arr[7][24]); } else aMSC_724.reset();
    if (num_arr[7][25] > 0) { aMSC_725.set_alphabet(num_arr[7][25]); aMSC_725.copy(ada_P_arr[7][25]); } else aMSC_725.reset();
    if (num_arr[7][26] > 0) { aMSC_726.set_alphabet(num_arr[7][26]); aMSC_726.copy(ada_P_arr[7][26]); } else aMSC_726.reset();
    if (num_arr[8][0 ] > 0) { aMSC_80.set_alphabet( num_arr[8][0 ]); aMSC_80.copy( ada_P_arr[8][0 ]); } else aMSC_80.reset();
    if (num_arr[8][1 ] > 0) { aMSC_81.set_alphabet( num_arr[8][1 ]); aMSC_81.copy( ada_P_arr[8][1 ]); } else aMSC_81.reset();
    if (num_arr[8][2 ] > 0) { aMSC_82.set_alphabet( num_arr[8][2 ]); aMSC_82.copy( ada_P_arr[8][2 ]); } else aMSC_82.reset();
    if (num_arr[8][3 ] > 0) { aMSC_83.set_alphabet( num_arr[8][3 ]); aMSC_83.copy( ada_P_arr[8][3 ]); } else aMSC_83.reset();
    if (num_arr[8][4 ] > 0) { aMSC_84.set_alphabet( num_arr[8][4 ]); aMSC_84.copy( ada_P_arr[8][4 ]); } else aMSC_84.reset();
    if (num_arr[8][5 ] > 0) { aMSC_85.set_alphabet( num_arr[8][5 ]); aMSC_85.copy( ada_P_arr[8][5 ]); } else aMSC_85.reset();
    if (num_arr[8][6 ] > 0) { aMSC_86.set_alphabet( num_arr[8][6 ]); aMSC_86.copy( ada_P_arr[8][6 ]); } else aMSC_86.reset();
    if (num_arr[8][7 ] > 0) { aMSC_87.set_alphabet( num_arr[8][7 ]); aMSC_87.copy( ada_P_arr[8][7 ]); } else aMSC_87.reset();
    if (num_arr[8][8 ] > 0) { aMSC_88.set_alphabet( num_arr[8][8 ]); aMSC_88.copy( ada_P_arr[8][8 ]); } else aMSC_88.reset();
    if (num_arr[8][9 ] > 0) { aMSC_89.set_alphabet( num_arr[8][9 ]); aMSC_89.copy( ada_P_arr[8][9 ]); } else aMSC_89.reset();
    if (num_arr[8][10] > 0) { aMSC_810.set_alphabet(num_arr[8][10]); aMSC_810.copy(ada_P_arr[8][10]); } else aMSC_810.reset();
    if (num_arr[8][11] > 0) { aMSC_811.set_alphabet(num_arr[8][11]); aMSC_811.copy(ada_P_arr[8][11]); } else aMSC_811.reset();
    if (num_arr[8][12] > 0) { aMSC_812.set_alphabet(num_arr[8][12]); aMSC_812.copy(ada_P_arr[8][12]); } else aMSC_812.reset();
    if (num_arr[8][13] > 0) { aMSC_813.set_alphabet(num_arr[8][13]); aMSC_813.copy(ada_P_arr[8][13]); } else aMSC_813.reset();
    if (num_arr[8][14] > 0) { aMSC_814.set_alphabet(num_arr[8][14]); aMSC_814.copy(ada_P_arr[8][14]); } else aMSC_814.reset();
    if (num_arr[8][15] > 0) { aMSC_815.set_alphabet(num_arr[8][15]); aMSC_815.copy(ada_P_arr[8][15]); } else aMSC_815.reset();
    if (num_arr[8][16] > 0) { aMSC_816.set_alphabet(num_arr[8][16]); aMSC_816.copy(ada_P_arr[8][16]); } else aMSC_816.reset();
    if (num_arr[8][17] > 0) { aMSC_817.set_alphabet(num_arr[8][17]); aMSC_817.copy(ada_P_arr[8][17]); } else aMSC_817.reset();
    if (num_arr[8][18] > 0) { aMSC_818.set_alphabet(num_arr[8][18]); aMSC_818.copy(ada_P_arr[8][18]); } else aMSC_818.reset();
    if (num_arr[8][19] > 0) { aMSC_819.set_alphabet(num_arr[8][19]); aMSC_819.copy(ada_P_arr[8][19]); } else aMSC_819.reset();
    if (num_arr[8][20] > 0) { aMSC_820.set_alphabet(num_arr[8][20]); aMSC_820.copy(ada_P_arr[8][20]); } else aMSC_820.reset();
    if (num_arr[8][21] > 0) { aMSC_821.set_alphabet(num_arr[8][21]); aMSC_821.copy(ada_P_arr[8][21]); } else aMSC_821.reset();
    if (num_arr[8][22] > 0) { aMSC_822.set_alphabet(num_arr[8][22]); aMSC_822.copy(ada_P_arr[8][22]); } else aMSC_822.reset();
    if (num_arr[8][23] > 0) { aMSC_823.set_alphabet(num_arr[8][23]); aMSC_823.copy(ada_P_arr[8][23]); } else aMSC_823.reset();
    if (num_arr[8][24] > 0) { aMSC_824.set_alphabet(num_arr[8][24]); aMSC_824.copy(ada_P_arr[8][24]); } else aMSC_824.reset();
    if (num_arr[8][25] > 0) { aMSC_825.set_alphabet(num_arr[8][25]); aMSC_825.copy(ada_P_arr[8][25]); } else aMSC_825.reset();
    if (num_arr[8][26] > 0) { aMSC_826.set_alphabet(num_arr[8][26]); aMSC_826.copy(ada_P_arr[8][26]); } else aMSC_826.reset();
    aEndFlag.reset();
	aChainType.reset();
    
    position_N = 1;
    position_A = 1000;
    position_K = 9;
}

void save_3OT()
{
	for (int i = 0; i < a3OT_L.data_symbols; i++) a3OT_L.distribution_forbidden[i] = a3OT_L.symbol_count[i]; a3OT_L.pre_count = a3OT_L.total_count;
	for (int i = 0; i < a3OT_A.data_symbols; i++) a3OT_A.distribution_forbidden[i] = a3OT_A.symbol_count[i]; a3OT_A.pre_count = a3OT_A.total_count;
	for (int i = 0; i < a3OT_B.data_symbols; i++) a3OT_B.distribution_forbidden[i] = a3OT_B.symbol_count[i]; a3OT_B.pre_count = a3OT_B.total_count;
	for (int i = 0; i < a3OT_R.data_symbols; i++) a3OT_R.distribution_forbidden[i] = a3OT_R.symbol_count[i]; a3OT_R.pre_count = a3OT_R.total_count;
	for (int i = 0; i < a3OT_I.data_symbols; i++) a3OT_I.distribution_forbidden[i] = a3OT_I.symbol_count[i]; a3OT_I.pre_count = a3OT_I.total_count;
	for (int i = 0; i < a3OT_0.data_symbols; i++) a3OT_0.distribution_forbidden[i] = a3OT_0.symbol_count[i]; a3OT_0.pre_count = a3OT_0.total_count;
	for (int i = 0; i < a3OT_1.data_symbols; i++) a3OT_1.distribution_forbidden[i] = a3OT_1.symbol_count[i]; a3OT_1.pre_count = a3OT_1.total_count;
	for (int i = 0; i < a3OT_2.data_symbols; i++) a3OT_2.distribution_forbidden[i] = a3OT_2.symbol_count[i]; a3OT_2.pre_count = a3OT_2.total_count;
	for (int i = 0; i < a3OT_00.data_symbols; i++) a3OT_00.distribution_forbidden[i] = a3OT_00.symbol_count[i]; a3OT_00.pre_count = a3OT_00.total_count;
	for (int i = 0; i < a3OT_01.data_symbols; i++) a3OT_01.distribution_forbidden[i] = a3OT_01.symbol_count[i]; a3OT_01.pre_count = a3OT_01.total_count;
	for (int i = 0; i < a3OT_02.data_symbols; i++) a3OT_02.distribution_forbidden[i] = a3OT_02.symbol_count[i]; a3OT_02.pre_count = a3OT_02.total_count;
	for (int i = 0; i < a3OT_10.data_symbols; i++) a3OT_10.distribution_forbidden[i] = a3OT_10.symbol_count[i]; a3OT_10.pre_count = a3OT_10.total_count;
	for (int i = 0; i < a3OT_11.data_symbols; i++) a3OT_11.distribution_forbidden[i] = a3OT_11.symbol_count[i]; a3OT_11.pre_count = a3OT_11.total_count;
	for (int i = 0; i < a3OT_12.data_symbols; i++) a3OT_12.distribution_forbidden[i] = a3OT_12.symbol_count[i]; a3OT_12.pre_count = a3OT_12.total_count;
	for (int i = 0; i < a3OT_20.data_symbols; i++) a3OT_20.distribution_forbidden[i] = a3OT_20.symbol_count[i]; a3OT_20.pre_count = a3OT_20.total_count;
	for (int i = 0; i < a3OT_21.data_symbols; i++) a3OT_21.distribution_forbidden[i] = a3OT_21.symbol_count[i]; a3OT_21.pre_count = a3OT_21.total_count;
	for (int i = 0; i < a3OT_22.data_symbols; i++) a3OT_22.distribution_forbidden[i] = a3OT_22.symbol_count[i]; a3OT_22.pre_count = a3OT_22.total_count;
	for (int i = 0; i < a3OT_000.data_symbols; i++) a3OT_000.distribution_forbidden[i] = a3OT_000.symbol_count[i]; a3OT_000.pre_count = a3OT_000.total_count;
	for (int i = 0; i < a3OT_001.data_symbols; i++) a3OT_001.distribution_forbidden[i] = a3OT_001.symbol_count[i]; a3OT_001.pre_count = a3OT_001.total_count;
	for (int i = 0; i < a3OT_002.data_symbols; i++) a3OT_002.distribution_forbidden[i] = a3OT_002.symbol_count[i]; a3OT_002.pre_count = a3OT_002.total_count;
	for (int i = 0; i < a3OT_010.data_symbols; i++) a3OT_010.distribution_forbidden[i] = a3OT_010.symbol_count[i]; a3OT_010.pre_count = a3OT_010.total_count;
	for (int i = 0; i < a3OT_011.data_symbols; i++) a3OT_011.distribution_forbidden[i] = a3OT_011.symbol_count[i]; a3OT_011.pre_count = a3OT_011.total_count;
	for (int i = 0; i < a3OT_012.data_symbols; i++) a3OT_012.distribution_forbidden[i] = a3OT_012.symbol_count[i]; a3OT_012.pre_count = a3OT_012.total_count;
	for (int i = 0; i < a3OT_020.data_symbols; i++) a3OT_020.distribution_forbidden[i] = a3OT_020.symbol_count[i]; a3OT_020.pre_count = a3OT_020.total_count;
	for (int i = 0; i < a3OT_021.data_symbols; i++) a3OT_021.distribution_forbidden[i] = a3OT_021.symbol_count[i]; a3OT_021.pre_count = a3OT_021.total_count;
	for (int i = 0; i < a3OT_022.data_symbols; i++) a3OT_022.distribution_forbidden[i] = a3OT_022.symbol_count[i]; a3OT_022.pre_count = a3OT_022.total_count;
	for (int i = 0; i < a3OT_100.data_symbols; i++) a3OT_100.distribution_forbidden[i] = a3OT_100.symbol_count[i]; a3OT_100.pre_count = a3OT_100.total_count;
	for (int i = 0; i < a3OT_101.data_symbols; i++) a3OT_101.distribution_forbidden[i] = a3OT_101.symbol_count[i]; a3OT_101.pre_count = a3OT_101.total_count;
	for (int i = 0; i < a3OT_102.data_symbols; i++) a3OT_102.distribution_forbidden[i] = a3OT_102.symbol_count[i]; a3OT_102.pre_count = a3OT_102.total_count;
	for (int i = 0; i < a3OT_110.data_symbols; i++) a3OT_110.distribution_forbidden[i] = a3OT_110.symbol_count[i]; a3OT_110.pre_count = a3OT_110.total_count;
	for (int i = 0; i < a3OT_111.data_symbols; i++) a3OT_111.distribution_forbidden[i] = a3OT_111.symbol_count[i]; a3OT_111.pre_count = a3OT_111.total_count;
	for (int i = 0; i < a3OT_112.data_symbols; i++) a3OT_112.distribution_forbidden[i] = a3OT_112.symbol_count[i]; a3OT_112.pre_count = a3OT_112.total_count;
	for (int i = 0; i < a3OT_120.data_symbols; i++) a3OT_120.distribution_forbidden[i] = a3OT_120.symbol_count[i]; a3OT_120.pre_count = a3OT_120.total_count;
	for (int i = 0; i < a3OT_121.data_symbols; i++) a3OT_121.distribution_forbidden[i] = a3OT_121.symbol_count[i]; a3OT_121.pre_count = a3OT_121.total_count;
	for (int i = 0; i < a3OT_122.data_symbols; i++) a3OT_122.distribution_forbidden[i] = a3OT_122.symbol_count[i]; a3OT_122.pre_count = a3OT_122.total_count;
	for (int i = 0; i < a3OT_200.data_symbols; i++) a3OT_200.distribution_forbidden[i] = a3OT_200.symbol_count[i]; a3OT_200.pre_count = a3OT_200.total_count;
	for (int i = 0; i < a3OT_201.data_symbols; i++) a3OT_201.distribution_forbidden[i] = a3OT_201.symbol_count[i]; a3OT_201.pre_count = a3OT_201.total_count;
	for (int i = 0; i < a3OT_202.data_symbols; i++) a3OT_202.distribution_forbidden[i] = a3OT_202.symbol_count[i]; a3OT_202.pre_count = a3OT_202.total_count;
	for (int i = 0; i < a3OT_210.data_symbols; i++) a3OT_210.distribution_forbidden[i] = a3OT_210.symbol_count[i]; a3OT_210.pre_count = a3OT_210.total_count;
	for (int i = 0; i < a3OT_211.data_symbols; i++) a3OT_211.distribution_forbidden[i] = a3OT_211.symbol_count[i]; a3OT_211.pre_count = a3OT_211.total_count;
	for (int i = 0; i < a3OT_212.data_symbols; i++) a3OT_212.distribution_forbidden[i] = a3OT_212.symbol_count[i]; a3OT_212.pre_count = a3OT_212.total_count;
	for (int i = 0; i < a3OT_220.data_symbols; i++) a3OT_220.distribution_forbidden[i] = a3OT_220.symbol_count[i]; a3OT_220.pre_count = a3OT_220.total_count;
	for (int i = 0; i < a3OT_221.data_symbols; i++) a3OT_221.distribution_forbidden[i] = a3OT_221.symbol_count[i]; a3OT_221.pre_count = a3OT_221.total_count;
	for (int i = 0; i < a3OT_222.data_symbols; i++) a3OT_222.distribution_forbidden[i] = a3OT_222.symbol_count[i]; a3OT_222.pre_count = a3OT_222.total_count;
	for (int i = 0; i < a3OT_0000.data_symbols; i++) a3OT_0000.distribution_forbidden[i] = a3OT_0000.symbol_count[i]; a3OT_0000.pre_count = a3OT_0000.total_count;
	for (int i = 0; i < a3OT_0001.data_symbols; i++) a3OT_0001.distribution_forbidden[i] = a3OT_0001.symbol_count[i]; a3OT_0001.pre_count = a3OT_0001.total_count;
	for (int i = 0; i < a3OT_0002.data_symbols; i++) a3OT_0002.distribution_forbidden[i] = a3OT_0002.symbol_count[i]; a3OT_0002.pre_count = a3OT_0002.total_count;
	for (int i = 0; i < a3OT_0010.data_symbols; i++) a3OT_0010.distribution_forbidden[i] = a3OT_0010.symbol_count[i]; a3OT_0010.pre_count = a3OT_0010.total_count;
	for (int i = 0; i < a3OT_0011.data_symbols; i++) a3OT_0011.distribution_forbidden[i] = a3OT_0011.symbol_count[i]; a3OT_0011.pre_count = a3OT_0011.total_count;
	for (int i = 0; i < a3OT_0012.data_symbols; i++) a3OT_0012.distribution_forbidden[i] = a3OT_0012.symbol_count[i]; a3OT_0012.pre_count = a3OT_0012.total_count;
	for (int i = 0; i < a3OT_0020.data_symbols; i++) a3OT_0020.distribution_forbidden[i] = a3OT_0020.symbol_count[i]; a3OT_0020.pre_count = a3OT_0020.total_count;
	for (int i = 0; i < a3OT_0021.data_symbols; i++) a3OT_0021.distribution_forbidden[i] = a3OT_0021.symbol_count[i]; a3OT_0021.pre_count = a3OT_0021.total_count;
	for (int i = 0; i < a3OT_0022.data_symbols; i++) a3OT_0022.distribution_forbidden[i] = a3OT_0022.symbol_count[i]; a3OT_0022.pre_count = a3OT_0022.total_count;
	for (int i = 0; i < a3OT_0100.data_symbols; i++) a3OT_0100.distribution_forbidden[i] = a3OT_0100.symbol_count[i]; a3OT_0100.pre_count = a3OT_0100.total_count;
	for (int i = 0; i < a3OT_0101.data_symbols; i++) a3OT_0101.distribution_forbidden[i] = a3OT_0101.symbol_count[i]; a3OT_0101.pre_count = a3OT_0101.total_count;
	for (int i = 0; i < a3OT_0102.data_symbols; i++) a3OT_0102.distribution_forbidden[i] = a3OT_0102.symbol_count[i]; a3OT_0102.pre_count = a3OT_0102.total_count;
	for (int i = 0; i < a3OT_0110.data_symbols; i++) a3OT_0110.distribution_forbidden[i] = a3OT_0110.symbol_count[i]; a3OT_0110.pre_count = a3OT_0110.total_count;
	for (int i = 0; i < a3OT_0111.data_symbols; i++) a3OT_0111.distribution_forbidden[i] = a3OT_0111.symbol_count[i]; a3OT_0111.pre_count = a3OT_0111.total_count;
	for (int i = 0; i < a3OT_0112.data_symbols; i++) a3OT_0112.distribution_forbidden[i] = a3OT_0112.symbol_count[i]; a3OT_0112.pre_count = a3OT_0112.total_count;
	for (int i = 0; i < a3OT_0120.data_symbols; i++) a3OT_0120.distribution_forbidden[i] = a3OT_0120.symbol_count[i]; a3OT_0120.pre_count = a3OT_0120.total_count;
	for (int i = 0; i < a3OT_0121.data_symbols; i++) a3OT_0121.distribution_forbidden[i] = a3OT_0121.symbol_count[i]; a3OT_0121.pre_count = a3OT_0121.total_count;
	for (int i = 0; i < a3OT_0122.data_symbols; i++) a3OT_0122.distribution_forbidden[i] = a3OT_0122.symbol_count[i]; a3OT_0122.pre_count = a3OT_0122.total_count;
	for (int i = 0; i < a3OT_0200.data_symbols; i++) a3OT_0200.distribution_forbidden[i] = a3OT_0200.symbol_count[i]; a3OT_0200.pre_count = a3OT_0200.total_count;
	for (int i = 0; i < a3OT_0201.data_symbols; i++) a3OT_0201.distribution_forbidden[i] = a3OT_0201.symbol_count[i]; a3OT_0201.pre_count = a3OT_0201.total_count;
	for (int i = 0; i < a3OT_0202.data_symbols; i++) a3OT_0202.distribution_forbidden[i] = a3OT_0202.symbol_count[i]; a3OT_0202.pre_count = a3OT_0202.total_count;
	for (int i = 0; i < a3OT_0210.data_symbols; i++) a3OT_0210.distribution_forbidden[i] = a3OT_0210.symbol_count[i]; a3OT_0210.pre_count = a3OT_0210.total_count;
	for (int i = 0; i < a3OT_0211.data_symbols; i++) a3OT_0211.distribution_forbidden[i] = a3OT_0211.symbol_count[i]; a3OT_0211.pre_count = a3OT_0211.total_count;
	for (int i = 0; i < a3OT_0212.data_symbols; i++) a3OT_0212.distribution_forbidden[i] = a3OT_0212.symbol_count[i]; a3OT_0212.pre_count = a3OT_0212.total_count;
	for (int i = 0; i < a3OT_0220.data_symbols; i++) a3OT_0220.distribution_forbidden[i] = a3OT_0220.symbol_count[i]; a3OT_0220.pre_count = a3OT_0220.total_count;
	for (int i = 0; i < a3OT_0221.data_symbols; i++) a3OT_0221.distribution_forbidden[i] = a3OT_0221.symbol_count[i]; a3OT_0221.pre_count = a3OT_0221.total_count;
	for (int i = 0; i < a3OT_0222.data_symbols; i++) a3OT_0222.distribution_forbidden[i] = a3OT_0222.symbol_count[i]; a3OT_0222.pre_count = a3OT_0222.total_count;
	for (int i = 0; i < a3OT_1000.data_symbols; i++) a3OT_1000.distribution_forbidden[i] = a3OT_1000.symbol_count[i]; a3OT_1000.pre_count = a3OT_1000.total_count;
	for (int i = 0; i < a3OT_1001.data_symbols; i++) a3OT_1001.distribution_forbidden[i] = a3OT_1001.symbol_count[i]; a3OT_1001.pre_count = a3OT_1001.total_count;
	for (int i = 0; i < a3OT_1002.data_symbols; i++) a3OT_1002.distribution_forbidden[i] = a3OT_1002.symbol_count[i]; a3OT_1002.pre_count = a3OT_1002.total_count;
	for (int i = 0; i < a3OT_1010.data_symbols; i++) a3OT_1010.distribution_forbidden[i] = a3OT_1010.symbol_count[i]; a3OT_1010.pre_count = a3OT_1010.total_count;
	for (int i = 0; i < a3OT_1011.data_symbols; i++) a3OT_1011.distribution_forbidden[i] = a3OT_1011.symbol_count[i]; a3OT_1011.pre_count = a3OT_1011.total_count;
	for (int i = 0; i < a3OT_1012.data_symbols; i++) a3OT_1012.distribution_forbidden[i] = a3OT_1012.symbol_count[i]; a3OT_1012.pre_count = a3OT_1012.total_count;
	for (int i = 0; i < a3OT_1020.data_symbols; i++) a3OT_1020.distribution_forbidden[i] = a3OT_1020.symbol_count[i]; a3OT_1020.pre_count = a3OT_1020.total_count;
	for (int i = 0; i < a3OT_1021.data_symbols; i++) a3OT_1021.distribution_forbidden[i] = a3OT_1021.symbol_count[i]; a3OT_1021.pre_count = a3OT_1021.total_count;
	for (int i = 0; i < a3OT_1022.data_symbols; i++) a3OT_1022.distribution_forbidden[i] = a3OT_1022.symbol_count[i]; a3OT_1022.pre_count = a3OT_1022.total_count;
	for (int i = 0; i < a3OT_1100.data_symbols; i++) a3OT_1100.distribution_forbidden[i] = a3OT_1100.symbol_count[i]; a3OT_1100.pre_count = a3OT_1100.total_count;
	for (int i = 0; i < a3OT_1101.data_symbols; i++) a3OT_1101.distribution_forbidden[i] = a3OT_1101.symbol_count[i]; a3OT_1101.pre_count = a3OT_1101.total_count;
	for (int i = 0; i < a3OT_1102.data_symbols; i++) a3OT_1102.distribution_forbidden[i] = a3OT_1102.symbol_count[i]; a3OT_1102.pre_count = a3OT_1102.total_count;
	for (int i = 0; i < a3OT_1110.data_symbols; i++) a3OT_1110.distribution_forbidden[i] = a3OT_1110.symbol_count[i]; a3OT_1110.pre_count = a3OT_1110.total_count;
	for (int i = 0; i < a3OT_1111.data_symbols; i++) a3OT_1111.distribution_forbidden[i] = a3OT_1111.symbol_count[i]; a3OT_1111.pre_count = a3OT_1111.total_count;
	for (int i = 0; i < a3OT_1112.data_symbols; i++) a3OT_1112.distribution_forbidden[i] = a3OT_1112.symbol_count[i]; a3OT_1112.pre_count = a3OT_1112.total_count;
	for (int i = 0; i < a3OT_1120.data_symbols; i++) a3OT_1120.distribution_forbidden[i] = a3OT_1120.symbol_count[i]; a3OT_1120.pre_count = a3OT_1120.total_count;
	for (int i = 0; i < a3OT_1121.data_symbols; i++) a3OT_1121.distribution_forbidden[i] = a3OT_1121.symbol_count[i]; a3OT_1121.pre_count = a3OT_1121.total_count;
	for (int i = 0; i < a3OT_1122.data_symbols; i++) a3OT_1122.distribution_forbidden[i] = a3OT_1122.symbol_count[i]; a3OT_1122.pre_count = a3OT_1122.total_count;
	for (int i = 0; i < a3OT_1200.data_symbols; i++) a3OT_1200.distribution_forbidden[i] = a3OT_1200.symbol_count[i]; a3OT_1200.pre_count = a3OT_1200.total_count;
	for (int i = 0; i < a3OT_1201.data_symbols; i++) a3OT_1201.distribution_forbidden[i] = a3OT_1201.symbol_count[i]; a3OT_1201.pre_count = a3OT_1201.total_count;
	for (int i = 0; i < a3OT_1202.data_symbols; i++) a3OT_1202.distribution_forbidden[i] = a3OT_1202.symbol_count[i]; a3OT_1202.pre_count = a3OT_1202.total_count;
	for (int i = 0; i < a3OT_1210.data_symbols; i++) a3OT_1210.distribution_forbidden[i] = a3OT_1210.symbol_count[i]; a3OT_1210.pre_count = a3OT_1210.total_count;
	for (int i = 0; i < a3OT_1211.data_symbols; i++) a3OT_1211.distribution_forbidden[i] = a3OT_1211.symbol_count[i]; a3OT_1211.pre_count = a3OT_1211.total_count;
	for (int i = 0; i < a3OT_1212.data_symbols; i++) a3OT_1212.distribution_forbidden[i] = a3OT_1212.symbol_count[i]; a3OT_1212.pre_count = a3OT_1212.total_count;
	for (int i = 0; i < a3OT_1220.data_symbols; i++) a3OT_1220.distribution_forbidden[i] = a3OT_1220.symbol_count[i]; a3OT_1220.pre_count = a3OT_1220.total_count;
	for (int i = 0; i < a3OT_1221.data_symbols; i++) a3OT_1221.distribution_forbidden[i] = a3OT_1221.symbol_count[i]; a3OT_1221.pre_count = a3OT_1221.total_count;
	for (int i = 0; i < a3OT_1222.data_symbols; i++) a3OT_1222.distribution_forbidden[i] = a3OT_1222.symbol_count[i]; a3OT_1222.pre_count = a3OT_1222.total_count;
	for (int i = 0; i < a3OT_2000.data_symbols; i++) a3OT_2000.distribution_forbidden[i] = a3OT_2000.symbol_count[i]; a3OT_2000.pre_count = a3OT_2000.total_count;
	for (int i = 0; i < a3OT_2001.data_symbols; i++) a3OT_2001.distribution_forbidden[i] = a3OT_2001.symbol_count[i]; a3OT_2001.pre_count = a3OT_2001.total_count;
	for (int i = 0; i < a3OT_2002.data_symbols; i++) a3OT_2002.distribution_forbidden[i] = a3OT_2002.symbol_count[i]; a3OT_2002.pre_count = a3OT_2002.total_count;
	for (int i = 0; i < a3OT_2010.data_symbols; i++) a3OT_2010.distribution_forbidden[i] = a3OT_2010.symbol_count[i]; a3OT_2010.pre_count = a3OT_2010.total_count;
	for (int i = 0; i < a3OT_2011.data_symbols; i++) a3OT_2011.distribution_forbidden[i] = a3OT_2011.symbol_count[i]; a3OT_2011.pre_count = a3OT_2011.total_count;
	for (int i = 0; i < a3OT_2012.data_symbols; i++) a3OT_2012.distribution_forbidden[i] = a3OT_2012.symbol_count[i]; a3OT_2012.pre_count = a3OT_2012.total_count;
	for (int i = 0; i < a3OT_2020.data_symbols; i++) a3OT_2020.distribution_forbidden[i] = a3OT_2020.symbol_count[i]; a3OT_2020.pre_count = a3OT_2020.total_count;
	for (int i = 0; i < a3OT_2021.data_symbols; i++) a3OT_2021.distribution_forbidden[i] = a3OT_2021.symbol_count[i]; a3OT_2021.pre_count = a3OT_2021.total_count;
	for (int i = 0; i < a3OT_2022.data_symbols; i++) a3OT_2022.distribution_forbidden[i] = a3OT_2022.symbol_count[i]; a3OT_2022.pre_count = a3OT_2022.total_count;
	for (int i = 0; i < a3OT_2100.data_symbols; i++) a3OT_2100.distribution_forbidden[i] = a3OT_2100.symbol_count[i]; a3OT_2100.pre_count = a3OT_2100.total_count;
	for (int i = 0; i < a3OT_2101.data_symbols; i++) a3OT_2101.distribution_forbidden[i] = a3OT_2101.symbol_count[i]; a3OT_2101.pre_count = a3OT_2101.total_count;
	for (int i = 0; i < a3OT_2102.data_symbols; i++) a3OT_2102.distribution_forbidden[i] = a3OT_2102.symbol_count[i]; a3OT_2102.pre_count = a3OT_2102.total_count;
	for (int i = 0; i < a3OT_2110.data_symbols; i++) a3OT_2110.distribution_forbidden[i] = a3OT_2110.symbol_count[i]; a3OT_2110.pre_count = a3OT_2110.total_count;
	for (int i = 0; i < a3OT_2111.data_symbols; i++) a3OT_2111.distribution_forbidden[i] = a3OT_2111.symbol_count[i]; a3OT_2111.pre_count = a3OT_2111.total_count;
	for (int i = 0; i < a3OT_2112.data_symbols; i++) a3OT_2112.distribution_forbidden[i] = a3OT_2112.symbol_count[i]; a3OT_2112.pre_count = a3OT_2112.total_count;
	for (int i = 0; i < a3OT_2120.data_symbols; i++) a3OT_2120.distribution_forbidden[i] = a3OT_2120.symbol_count[i]; a3OT_2120.pre_count = a3OT_2120.total_count;
	for (int i = 0; i < a3OT_2121.data_symbols; i++) a3OT_2121.distribution_forbidden[i] = a3OT_2121.symbol_count[i]; a3OT_2121.pre_count = a3OT_2121.total_count;
	for (int i = 0; i < a3OT_2122.data_symbols; i++) a3OT_2122.distribution_forbidden[i] = a3OT_2122.symbol_count[i]; a3OT_2122.pre_count = a3OT_2122.total_count;
	for (int i = 0; i < a3OT_2200.data_symbols; i++) a3OT_2200.distribution_forbidden[i] = a3OT_2200.symbol_count[i]; a3OT_2200.pre_count = a3OT_2200.total_count;
	for (int i = 0; i < a3OT_2201.data_symbols; i++) a3OT_2201.distribution_forbidden[i] = a3OT_2201.symbol_count[i]; a3OT_2201.pre_count = a3OT_2201.total_count;
	for (int i = 0; i < a3OT_2202.data_symbols; i++) a3OT_2202.distribution_forbidden[i] = a3OT_2202.symbol_count[i]; a3OT_2202.pre_count = a3OT_2202.total_count;
	for (int i = 0; i < a3OT_2210.data_symbols; i++) a3OT_2210.distribution_forbidden[i] = a3OT_2210.symbol_count[i]; a3OT_2210.pre_count = a3OT_2210.total_count;
	for (int i = 0; i < a3OT_2211.data_symbols; i++) a3OT_2211.distribution_forbidden[i] = a3OT_2211.symbol_count[i]; a3OT_2211.pre_count = a3OT_2211.total_count;
	for (int i = 0; i < a3OT_2212.data_symbols; i++) a3OT_2212.distribution_forbidden[i] = a3OT_2212.symbol_count[i]; a3OT_2212.pre_count = a3OT_2212.total_count;
	for (int i = 0; i < a3OT_2220.data_symbols; i++) a3OT_2220.distribution_forbidden[i] = a3OT_2220.symbol_count[i]; a3OT_2220.pre_count = a3OT_2220.total_count;
	for (int i = 0; i < a3OT_2221.data_symbols; i++) a3OT_2221.distribution_forbidden[i] = a3OT_2221.symbol_count[i]; a3OT_2221.pre_count = a3OT_2221.total_count;
	for (int i = 0; i < a3OT_2222.data_symbols; i++) a3OT_2222.distribution_forbidden[i] = a3OT_2222.symbol_count[i]; a3OT_2222.pre_count = a3OT_2222.total_count;
}

void restore_3OT()
{
	for (int i = 0; i < a3OT_L.data_symbols; i++) a3OT_L.symbol_count[i] = a3OT_L.distribution_forbidden[i]; a3OT_L.total_count = a3OT_L.pre_count;
	for (int i = 0; i < a3OT_A.data_symbols; i++) a3OT_A.symbol_count[i] = a3OT_A.distribution_forbidden[i]; a3OT_A.total_count = a3OT_A.pre_count;
	for (int i = 0; i < a3OT_B.data_symbols; i++) a3OT_B.symbol_count[i] = a3OT_B.distribution_forbidden[i]; a3OT_B.total_count = a3OT_B.pre_count;
	for (int i = 0; i < a3OT_R.data_symbols; i++) a3OT_R.symbol_count[i] = a3OT_R.distribution_forbidden[i]; a3OT_R.total_count = a3OT_R.pre_count;
	for (int i = 0; i < a3OT_I.data_symbols; i++) a3OT_I.symbol_count[i] = a3OT_I.distribution_forbidden[i]; a3OT_I.total_count = a3OT_I.pre_count;
	for (int i = 0; i < a3OT_0.data_symbols; i++) a3OT_0.symbol_count[i] = a3OT_0.distribution_forbidden[i]; a3OT_0.total_count = a3OT_0.pre_count;
	for (int i = 0; i < a3OT_1.data_symbols; i++) a3OT_1.symbol_count[i] = a3OT_1.distribution_forbidden[i]; a3OT_1.total_count = a3OT_1.pre_count;
	for (int i = 0; i < a3OT_2.data_symbols; i++) a3OT_2.symbol_count[i] = a3OT_2.distribution_forbidden[i]; a3OT_2.total_count = a3OT_2.pre_count;
	for (int i = 0; i < a3OT_00.data_symbols; i++) a3OT_00.symbol_count[i] = a3OT_00.distribution_forbidden[i]; a3OT_00.total_count = a3OT_00.pre_count;
	for (int i = 0; i < a3OT_01.data_symbols; i++) a3OT_01.symbol_count[i] = a3OT_01.distribution_forbidden[i]; a3OT_01.total_count = a3OT_01.pre_count;
	for (int i = 0; i < a3OT_02.data_symbols; i++) a3OT_02.symbol_count[i] = a3OT_02.distribution_forbidden[i]; a3OT_02.total_count = a3OT_02.pre_count;
	for (int i = 0; i < a3OT_10.data_symbols; i++) a3OT_10.symbol_count[i] = a3OT_10.distribution_forbidden[i]; a3OT_10.total_count = a3OT_10.pre_count;
	for (int i = 0; i < a3OT_11.data_symbols; i++) a3OT_11.symbol_count[i] = a3OT_11.distribution_forbidden[i]; a3OT_11.total_count = a3OT_11.pre_count;
	for (int i = 0; i < a3OT_12.data_symbols; i++) a3OT_12.symbol_count[i] = a3OT_12.distribution_forbidden[i]; a3OT_12.total_count = a3OT_12.pre_count;
	for (int i = 0; i < a3OT_20.data_symbols; i++) a3OT_20.symbol_count[i] = a3OT_20.distribution_forbidden[i]; a3OT_20.total_count = a3OT_20.pre_count;
	for (int i = 0; i < a3OT_21.data_symbols; i++) a3OT_21.symbol_count[i] = a3OT_21.distribution_forbidden[i]; a3OT_21.total_count = a3OT_21.pre_count;
	for (int i = 0; i < a3OT_22.data_symbols; i++) a3OT_22.symbol_count[i] = a3OT_22.distribution_forbidden[i]; a3OT_22.total_count = a3OT_22.pre_count;
	for (int i = 0; i < a3OT_000.data_symbols; i++) a3OT_000.symbol_count[i] = a3OT_000.distribution_forbidden[i]; a3OT_000.total_count = a3OT_000.pre_count;
	for (int i = 0; i < a3OT_001.data_symbols; i++) a3OT_001.symbol_count[i] = a3OT_001.distribution_forbidden[i]; a3OT_001.total_count = a3OT_001.pre_count;
	for (int i = 0; i < a3OT_002.data_symbols; i++) a3OT_002.symbol_count[i] = a3OT_002.distribution_forbidden[i]; a3OT_002.total_count = a3OT_002.pre_count;
	for (int i = 0; i < a3OT_010.data_symbols; i++) a3OT_010.symbol_count[i] = a3OT_010.distribution_forbidden[i]; a3OT_010.total_count = a3OT_010.pre_count;
	for (int i = 0; i < a3OT_011.data_symbols; i++) a3OT_011.symbol_count[i] = a3OT_011.distribution_forbidden[i]; a3OT_011.total_count = a3OT_011.pre_count;
	for (int i = 0; i < a3OT_012.data_symbols; i++) a3OT_012.symbol_count[i] = a3OT_012.distribution_forbidden[i]; a3OT_012.total_count = a3OT_012.pre_count;
	for (int i = 0; i < a3OT_020.data_symbols; i++) a3OT_020.symbol_count[i] = a3OT_020.distribution_forbidden[i]; a3OT_020.total_count = a3OT_020.pre_count;
	for (int i = 0; i < a3OT_021.data_symbols; i++) a3OT_021.symbol_count[i] = a3OT_021.distribution_forbidden[i]; a3OT_021.total_count = a3OT_021.pre_count;
	for (int i = 0; i < a3OT_022.data_symbols; i++) a3OT_022.symbol_count[i] = a3OT_022.distribution_forbidden[i]; a3OT_022.total_count = a3OT_022.pre_count;
	for (int i = 0; i < a3OT_100.data_symbols; i++) a3OT_100.symbol_count[i] = a3OT_100.distribution_forbidden[i]; a3OT_100.total_count = a3OT_100.pre_count;
	for (int i = 0; i < a3OT_101.data_symbols; i++) a3OT_101.symbol_count[i] = a3OT_101.distribution_forbidden[i]; a3OT_101.total_count = a3OT_101.pre_count;
	for (int i = 0; i < a3OT_102.data_symbols; i++) a3OT_102.symbol_count[i] = a3OT_102.distribution_forbidden[i]; a3OT_102.total_count = a3OT_102.pre_count;
	for (int i = 0; i < a3OT_110.data_symbols; i++) a3OT_110.symbol_count[i] = a3OT_110.distribution_forbidden[i]; a3OT_110.total_count = a3OT_110.pre_count;
	for (int i = 0; i < a3OT_111.data_symbols; i++) a3OT_111.symbol_count[i] = a3OT_111.distribution_forbidden[i]; a3OT_111.total_count = a3OT_111.pre_count;
	for (int i = 0; i < a3OT_112.data_symbols; i++) a3OT_112.symbol_count[i] = a3OT_112.distribution_forbidden[i]; a3OT_112.total_count = a3OT_112.pre_count;
	for (int i = 0; i < a3OT_120.data_symbols; i++) a3OT_120.symbol_count[i] = a3OT_120.distribution_forbidden[i]; a3OT_120.total_count = a3OT_120.pre_count;
	for (int i = 0; i < a3OT_121.data_symbols; i++) a3OT_121.symbol_count[i] = a3OT_121.distribution_forbidden[i]; a3OT_121.total_count = a3OT_121.pre_count;
	for (int i = 0; i < a3OT_122.data_symbols; i++) a3OT_122.symbol_count[i] = a3OT_122.distribution_forbidden[i]; a3OT_122.total_count = a3OT_122.pre_count;
	for (int i = 0; i < a3OT_200.data_symbols; i++) a3OT_200.symbol_count[i] = a3OT_200.distribution_forbidden[i]; a3OT_200.total_count = a3OT_200.pre_count;
	for (int i = 0; i < a3OT_201.data_symbols; i++) a3OT_201.symbol_count[i] = a3OT_201.distribution_forbidden[i]; a3OT_201.total_count = a3OT_201.pre_count;
	for (int i = 0; i < a3OT_202.data_symbols; i++) a3OT_202.symbol_count[i] = a3OT_202.distribution_forbidden[i]; a3OT_202.total_count = a3OT_202.pre_count;
	for (int i = 0; i < a3OT_210.data_symbols; i++) a3OT_210.symbol_count[i] = a3OT_210.distribution_forbidden[i]; a3OT_210.total_count = a3OT_210.pre_count;
	for (int i = 0; i < a3OT_211.data_symbols; i++) a3OT_211.symbol_count[i] = a3OT_211.distribution_forbidden[i]; a3OT_211.total_count = a3OT_211.pre_count;
	for (int i = 0; i < a3OT_212.data_symbols; i++) a3OT_212.symbol_count[i] = a3OT_212.distribution_forbidden[i]; a3OT_212.total_count = a3OT_212.pre_count;
	for (int i = 0; i < a3OT_220.data_symbols; i++) a3OT_220.symbol_count[i] = a3OT_220.distribution_forbidden[i]; a3OT_220.total_count = a3OT_220.pre_count;
	for (int i = 0; i < a3OT_221.data_symbols; i++) a3OT_221.symbol_count[i] = a3OT_221.distribution_forbidden[i]; a3OT_221.total_count = a3OT_221.pre_count;
	for (int i = 0; i < a3OT_222.data_symbols; i++) a3OT_222.symbol_count[i] = a3OT_222.distribution_forbidden[i]; a3OT_222.total_count = a3OT_222.pre_count;
	for (int i = 0; i < a3OT_0000.data_symbols; i++) a3OT_0000.symbol_count[i] = a3OT_0000.distribution_forbidden[i]; a3OT_0000.total_count = a3OT_0000.pre_count;
	for (int i = 0; i < a3OT_0001.data_symbols; i++) a3OT_0001.symbol_count[i] = a3OT_0001.distribution_forbidden[i]; a3OT_0001.total_count = a3OT_0001.pre_count;
	for (int i = 0; i < a3OT_0002.data_symbols; i++) a3OT_0002.symbol_count[i] = a3OT_0002.distribution_forbidden[i]; a3OT_0002.total_count = a3OT_0002.pre_count;
	for (int i = 0; i < a3OT_0010.data_symbols; i++) a3OT_0010.symbol_count[i] = a3OT_0010.distribution_forbidden[i]; a3OT_0010.total_count = a3OT_0010.pre_count;
	for (int i = 0; i < a3OT_0011.data_symbols; i++) a3OT_0011.symbol_count[i] = a3OT_0011.distribution_forbidden[i]; a3OT_0011.total_count = a3OT_0011.pre_count;
	for (int i = 0; i < a3OT_0012.data_symbols; i++) a3OT_0012.symbol_count[i] = a3OT_0012.distribution_forbidden[i]; a3OT_0012.total_count = a3OT_0012.pre_count;
	for (int i = 0; i < a3OT_0020.data_symbols; i++) a3OT_0020.symbol_count[i] = a3OT_0020.distribution_forbidden[i]; a3OT_0020.total_count = a3OT_0020.pre_count;
	for (int i = 0; i < a3OT_0021.data_symbols; i++) a3OT_0021.symbol_count[i] = a3OT_0021.distribution_forbidden[i]; a3OT_0021.total_count = a3OT_0021.pre_count;
	for (int i = 0; i < a3OT_0022.data_symbols; i++) a3OT_0022.symbol_count[i] = a3OT_0022.distribution_forbidden[i]; a3OT_0022.total_count = a3OT_0022.pre_count;
	for (int i = 0; i < a3OT_0100.data_symbols; i++) a3OT_0100.symbol_count[i] = a3OT_0100.distribution_forbidden[i]; a3OT_0100.total_count = a3OT_0100.pre_count;
	for (int i = 0; i < a3OT_0101.data_symbols; i++) a3OT_0101.symbol_count[i] = a3OT_0101.distribution_forbidden[i]; a3OT_0101.total_count = a3OT_0101.pre_count;
	for (int i = 0; i < a3OT_0102.data_symbols; i++) a3OT_0102.symbol_count[i] = a3OT_0102.distribution_forbidden[i]; a3OT_0102.total_count = a3OT_0102.pre_count;
	for (int i = 0; i < a3OT_0110.data_symbols; i++) a3OT_0110.symbol_count[i] = a3OT_0110.distribution_forbidden[i]; a3OT_0110.total_count = a3OT_0110.pre_count;
	for (int i = 0; i < a3OT_0111.data_symbols; i++) a3OT_0111.symbol_count[i] = a3OT_0111.distribution_forbidden[i]; a3OT_0111.total_count = a3OT_0111.pre_count;
	for (int i = 0; i < a3OT_0112.data_symbols; i++) a3OT_0112.symbol_count[i] = a3OT_0112.distribution_forbidden[i]; a3OT_0112.total_count = a3OT_0112.pre_count;
	for (int i = 0; i < a3OT_0120.data_symbols; i++) a3OT_0120.symbol_count[i] = a3OT_0120.distribution_forbidden[i]; a3OT_0120.total_count = a3OT_0120.pre_count;
	for (int i = 0; i < a3OT_0121.data_symbols; i++) a3OT_0121.symbol_count[i] = a3OT_0121.distribution_forbidden[i]; a3OT_0121.total_count = a3OT_0121.pre_count;
	for (int i = 0; i < a3OT_0122.data_symbols; i++) a3OT_0122.symbol_count[i] = a3OT_0122.distribution_forbidden[i]; a3OT_0122.total_count = a3OT_0122.pre_count;
	for (int i = 0; i < a3OT_0200.data_symbols; i++) a3OT_0200.symbol_count[i] = a3OT_0200.distribution_forbidden[i]; a3OT_0200.total_count = a3OT_0200.pre_count;
	for (int i = 0; i < a3OT_0201.data_symbols; i++) a3OT_0201.symbol_count[i] = a3OT_0201.distribution_forbidden[i]; a3OT_0201.total_count = a3OT_0201.pre_count;
	for (int i = 0; i < a3OT_0202.data_symbols; i++) a3OT_0202.symbol_count[i] = a3OT_0202.distribution_forbidden[i]; a3OT_0202.total_count = a3OT_0202.pre_count;
	for (int i = 0; i < a3OT_0210.data_symbols; i++) a3OT_0210.symbol_count[i] = a3OT_0210.distribution_forbidden[i]; a3OT_0210.total_count = a3OT_0210.pre_count;
	for (int i = 0; i < a3OT_0211.data_symbols; i++) a3OT_0211.symbol_count[i] = a3OT_0211.distribution_forbidden[i]; a3OT_0211.total_count = a3OT_0211.pre_count;
	for (int i = 0; i < a3OT_0212.data_symbols; i++) a3OT_0212.symbol_count[i] = a3OT_0212.distribution_forbidden[i]; a3OT_0212.total_count = a3OT_0212.pre_count;
	for (int i = 0; i < a3OT_0220.data_symbols; i++) a3OT_0220.symbol_count[i] = a3OT_0220.distribution_forbidden[i]; a3OT_0220.total_count = a3OT_0220.pre_count;
	for (int i = 0; i < a3OT_0221.data_symbols; i++) a3OT_0221.symbol_count[i] = a3OT_0221.distribution_forbidden[i]; a3OT_0221.total_count = a3OT_0221.pre_count;
	for (int i = 0; i < a3OT_0222.data_symbols; i++) a3OT_0222.symbol_count[i] = a3OT_0222.distribution_forbidden[i]; a3OT_0222.total_count = a3OT_0222.pre_count;
	for (int i = 0; i < a3OT_1000.data_symbols; i++) a3OT_1000.symbol_count[i] = a3OT_1000.distribution_forbidden[i]; a3OT_1000.total_count = a3OT_1000.pre_count;
	for (int i = 0; i < a3OT_1001.data_symbols; i++) a3OT_1001.symbol_count[i] = a3OT_1001.distribution_forbidden[i]; a3OT_1001.total_count = a3OT_1001.pre_count;
	for (int i = 0; i < a3OT_1002.data_symbols; i++) a3OT_1002.symbol_count[i] = a3OT_1002.distribution_forbidden[i]; a3OT_1002.total_count = a3OT_1002.pre_count;
	for (int i = 0; i < a3OT_1010.data_symbols; i++) a3OT_1010.symbol_count[i] = a3OT_1010.distribution_forbidden[i]; a3OT_1010.total_count = a3OT_1010.pre_count;
	for (int i = 0; i < a3OT_1011.data_symbols; i++) a3OT_1011.symbol_count[i] = a3OT_1011.distribution_forbidden[i]; a3OT_1011.total_count = a3OT_1011.pre_count;
	for (int i = 0; i < a3OT_1012.data_symbols; i++) a3OT_1012.symbol_count[i] = a3OT_1012.distribution_forbidden[i]; a3OT_1012.total_count = a3OT_1012.pre_count;
	for (int i = 0; i < a3OT_1020.data_symbols; i++) a3OT_1020.symbol_count[i] = a3OT_1020.distribution_forbidden[i]; a3OT_1020.total_count = a3OT_1020.pre_count;
	for (int i = 0; i < a3OT_1021.data_symbols; i++) a3OT_1021.symbol_count[i] = a3OT_1021.distribution_forbidden[i]; a3OT_1021.total_count = a3OT_1021.pre_count;
	for (int i = 0; i < a3OT_1022.data_symbols; i++) a3OT_1022.symbol_count[i] = a3OT_1022.distribution_forbidden[i]; a3OT_1022.total_count = a3OT_1022.pre_count;
	for (int i = 0; i < a3OT_1100.data_symbols; i++) a3OT_1100.symbol_count[i] = a3OT_1100.distribution_forbidden[i]; a3OT_1100.total_count = a3OT_1100.pre_count;
	for (int i = 0; i < a3OT_1101.data_symbols; i++) a3OT_1101.symbol_count[i] = a3OT_1101.distribution_forbidden[i]; a3OT_1101.total_count = a3OT_1101.pre_count;
	for (int i = 0; i < a3OT_1102.data_symbols; i++) a3OT_1102.symbol_count[i] = a3OT_1102.distribution_forbidden[i]; a3OT_1102.total_count = a3OT_1102.pre_count;
	for (int i = 0; i < a3OT_1110.data_symbols; i++) a3OT_1110.symbol_count[i] = a3OT_1110.distribution_forbidden[i]; a3OT_1110.total_count = a3OT_1110.pre_count;
	for (int i = 0; i < a3OT_1111.data_symbols; i++) a3OT_1111.symbol_count[i] = a3OT_1111.distribution_forbidden[i]; a3OT_1111.total_count = a3OT_1111.pre_count;
	for (int i = 0; i < a3OT_1112.data_symbols; i++) a3OT_1112.symbol_count[i] = a3OT_1112.distribution_forbidden[i]; a3OT_1112.total_count = a3OT_1112.pre_count;
	for (int i = 0; i < a3OT_1120.data_symbols; i++) a3OT_1120.symbol_count[i] = a3OT_1120.distribution_forbidden[i]; a3OT_1120.total_count = a3OT_1120.pre_count;
	for (int i = 0; i < a3OT_1121.data_symbols; i++) a3OT_1121.symbol_count[i] = a3OT_1121.distribution_forbidden[i]; a3OT_1121.total_count = a3OT_1121.pre_count;
	for (int i = 0; i < a3OT_1122.data_symbols; i++) a3OT_1122.symbol_count[i] = a3OT_1122.distribution_forbidden[i]; a3OT_1122.total_count = a3OT_1122.pre_count;
	for (int i = 0; i < a3OT_1200.data_symbols; i++) a3OT_1200.symbol_count[i] = a3OT_1200.distribution_forbidden[i]; a3OT_1200.total_count = a3OT_1200.pre_count;
	for (int i = 0; i < a3OT_1201.data_symbols; i++) a3OT_1201.symbol_count[i] = a3OT_1201.distribution_forbidden[i]; a3OT_1201.total_count = a3OT_1201.pre_count;
	for (int i = 0; i < a3OT_1202.data_symbols; i++) a3OT_1202.symbol_count[i] = a3OT_1202.distribution_forbidden[i]; a3OT_1202.total_count = a3OT_1202.pre_count;
	for (int i = 0; i < a3OT_1210.data_symbols; i++) a3OT_1210.symbol_count[i] = a3OT_1210.distribution_forbidden[i]; a3OT_1210.total_count = a3OT_1210.pre_count;
	for (int i = 0; i < a3OT_1211.data_symbols; i++) a3OT_1211.symbol_count[i] = a3OT_1211.distribution_forbidden[i]; a3OT_1211.total_count = a3OT_1211.pre_count;
	for (int i = 0; i < a3OT_1212.data_symbols; i++) a3OT_1212.symbol_count[i] = a3OT_1212.distribution_forbidden[i]; a3OT_1212.total_count = a3OT_1212.pre_count;
	for (int i = 0; i < a3OT_1220.data_symbols; i++) a3OT_1220.symbol_count[i] = a3OT_1220.distribution_forbidden[i]; a3OT_1220.total_count = a3OT_1220.pre_count;
	for (int i = 0; i < a3OT_1221.data_symbols; i++) a3OT_1221.symbol_count[i] = a3OT_1221.distribution_forbidden[i]; a3OT_1221.total_count = a3OT_1221.pre_count;
	for (int i = 0; i < a3OT_1222.data_symbols; i++) a3OT_1222.symbol_count[i] = a3OT_1222.distribution_forbidden[i]; a3OT_1222.total_count = a3OT_1222.pre_count;
	for (int i = 0; i < a3OT_2000.data_symbols; i++) a3OT_2000.symbol_count[i] = a3OT_2000.distribution_forbidden[i]; a3OT_2000.total_count = a3OT_2000.pre_count;
	for (int i = 0; i < a3OT_2001.data_symbols; i++) a3OT_2001.symbol_count[i] = a3OT_2001.distribution_forbidden[i]; a3OT_2001.total_count = a3OT_2001.pre_count;
	for (int i = 0; i < a3OT_2002.data_symbols; i++) a3OT_2002.symbol_count[i] = a3OT_2002.distribution_forbidden[i]; a3OT_2002.total_count = a3OT_2002.pre_count;
	for (int i = 0; i < a3OT_2010.data_symbols; i++) a3OT_2010.symbol_count[i] = a3OT_2010.distribution_forbidden[i]; a3OT_2010.total_count = a3OT_2010.pre_count;
	for (int i = 0; i < a3OT_2011.data_symbols; i++) a3OT_2011.symbol_count[i] = a3OT_2011.distribution_forbidden[i]; a3OT_2011.total_count = a3OT_2011.pre_count;
	for (int i = 0; i < a3OT_2012.data_symbols; i++) a3OT_2012.symbol_count[i] = a3OT_2012.distribution_forbidden[i]; a3OT_2012.total_count = a3OT_2012.pre_count;
	for (int i = 0; i < a3OT_2020.data_symbols; i++) a3OT_2020.symbol_count[i] = a3OT_2020.distribution_forbidden[i]; a3OT_2020.total_count = a3OT_2020.pre_count;
	for (int i = 0; i < a3OT_2021.data_symbols; i++) a3OT_2021.symbol_count[i] = a3OT_2021.distribution_forbidden[i]; a3OT_2021.total_count = a3OT_2021.pre_count;
	for (int i = 0; i < a3OT_2022.data_symbols; i++) a3OT_2022.symbol_count[i] = a3OT_2022.distribution_forbidden[i]; a3OT_2022.total_count = a3OT_2022.pre_count;
	for (int i = 0; i < a3OT_2100.data_symbols; i++) a3OT_2100.symbol_count[i] = a3OT_2100.distribution_forbidden[i]; a3OT_2100.total_count = a3OT_2100.pre_count;
	for (int i = 0; i < a3OT_2101.data_symbols; i++) a3OT_2101.symbol_count[i] = a3OT_2101.distribution_forbidden[i]; a3OT_2101.total_count = a3OT_2101.pre_count;
	for (int i = 0; i < a3OT_2102.data_symbols; i++) a3OT_2102.symbol_count[i] = a3OT_2102.distribution_forbidden[i]; a3OT_2102.total_count = a3OT_2102.pre_count;
	for (int i = 0; i < a3OT_2110.data_symbols; i++) a3OT_2110.symbol_count[i] = a3OT_2110.distribution_forbidden[i]; a3OT_2110.total_count = a3OT_2110.pre_count;
	for (int i = 0; i < a3OT_2111.data_symbols; i++) a3OT_2111.symbol_count[i] = a3OT_2111.distribution_forbidden[i]; a3OT_2111.total_count = a3OT_2111.pre_count;
	for (int i = 0; i < a3OT_2112.data_symbols; i++) a3OT_2112.symbol_count[i] = a3OT_2112.distribution_forbidden[i]; a3OT_2112.total_count = a3OT_2112.pre_count;
	for (int i = 0; i < a3OT_2120.data_symbols; i++) a3OT_2120.symbol_count[i] = a3OT_2120.distribution_forbidden[i]; a3OT_2120.total_count = a3OT_2120.pre_count;
	for (int i = 0; i < a3OT_2121.data_symbols; i++) a3OT_2121.symbol_count[i] = a3OT_2121.distribution_forbidden[i]; a3OT_2121.total_count = a3OT_2121.pre_count;
	for (int i = 0; i < a3OT_2122.data_symbols; i++) a3OT_2122.symbol_count[i] = a3OT_2122.distribution_forbidden[i]; a3OT_2122.total_count = a3OT_2122.pre_count;
	for (int i = 0; i < a3OT_2200.data_symbols; i++) a3OT_2200.symbol_count[i] = a3OT_2200.distribution_forbidden[i]; a3OT_2200.total_count = a3OT_2200.pre_count;
	for (int i = 0; i < a3OT_2201.data_symbols; i++) a3OT_2201.symbol_count[i] = a3OT_2201.distribution_forbidden[i]; a3OT_2201.total_count = a3OT_2201.pre_count;
	for (int i = 0; i < a3OT_2202.data_symbols; i++) a3OT_2202.symbol_count[i] = a3OT_2202.distribution_forbidden[i]; a3OT_2202.total_count = a3OT_2202.pre_count;
	for (int i = 0; i < a3OT_2210.data_symbols; i++) a3OT_2210.symbol_count[i] = a3OT_2210.distribution_forbidden[i]; a3OT_2210.total_count = a3OT_2210.pre_count;
	for (int i = 0; i < a3OT_2211.data_symbols; i++) a3OT_2211.symbol_count[i] = a3OT_2211.distribution_forbidden[i]; a3OT_2211.total_count = a3OT_2211.pre_count;
	for (int i = 0; i < a3OT_2212.data_symbols; i++) a3OT_2212.symbol_count[i] = a3OT_2212.distribution_forbidden[i]; a3OT_2212.total_count = a3OT_2212.pre_count;
	for (int i = 0; i < a3OT_2220.data_symbols; i++) a3OT_2220.symbol_count[i] = a3OT_2220.distribution_forbidden[i]; a3OT_2220.total_count = a3OT_2220.pre_count;
	for (int i = 0; i < a3OT_2221.data_symbols; i++) a3OT_2221.symbol_count[i] = a3OT_2221.distribution_forbidden[i]; a3OT_2221.total_count = a3OT_2221.pre_count;
	for (int i = 0; i < a3OT_2222.data_symbols; i++) a3OT_2222.symbol_count[i] = a3OT_2222.distribution_forbidden[i]; a3OT_2222.total_count = a3OT_2222.pre_count;
}

void save_MSC()
{
	for (int i = 0; i < aMSC_L.data_symbols; i++) aMSC_L.distribution_forbidden[i] = aMSC_L.symbol_count[i]; aMSC_L.pre_count = aMSC_L.total_count;
	for (int i = 0; i < aMSC_A.data_symbols; i++) aMSC_A.distribution_forbidden[i] = aMSC_A.symbol_count[i]; aMSC_A.pre_count = aMSC_A.total_count;
	for (int i = 0; i < aMSC_B.data_symbols; i++) aMSC_B.distribution_forbidden[i] = aMSC_B.symbol_count[i]; aMSC_B.pre_count = aMSC_B.total_count;
	for (int i = 0; i < aMSC_R.data_symbols; i++) aMSC_R.distribution_forbidden[i] = aMSC_R.symbol_count[i]; aMSC_R.pre_count = aMSC_R.total_count;
	for (int i = 0; i < aMSC_I.data_symbols; i++) aMSC_I.distribution_forbidden[i] = aMSC_I.symbol_count[i]; aMSC_I.pre_count = aMSC_I.total_count;
	for (int i = 0; i < aMSC_0.data_symbols; i++) aMSC_0.distribution_forbidden[i] = aMSC_0.symbol_count[i]; aMSC_0.pre_count = aMSC_0.total_count;
	for (int i = 0; i < aMSC_1.data_symbols; i++) aMSC_1.distribution_forbidden[i] = aMSC_1.symbol_count[i]; aMSC_1.pre_count = aMSC_1.total_count;
	for (int i = 0; i < aMSC_2.data_symbols; i++) aMSC_2.distribution_forbidden[i] = aMSC_2.symbol_count[i]; aMSC_2.pre_count = aMSC_2.total_count;
	for (int i = 0; i < aMSC_3.data_symbols; i++) aMSC_3.distribution_forbidden[i] = aMSC_3.symbol_count[i]; aMSC_3.pre_count = aMSC_3.total_count;
	for (int i = 0; i < aMSC_4.data_symbols; i++) aMSC_4.distribution_forbidden[i] = aMSC_4.symbol_count[i]; aMSC_4.pre_count = aMSC_4.total_count;
	for (int i = 0; i < aMSC_5.data_symbols; i++) aMSC_5.distribution_forbidden[i] = aMSC_5.symbol_count[i]; aMSC_5.pre_count = aMSC_5.total_count;
	for (int i = 0; i < aMSC_6.data_symbols; i++) aMSC_6.distribution_forbidden[i] = aMSC_6.symbol_count[i]; aMSC_6.pre_count = aMSC_6.total_count;
	for (int i = 0; i < aMSC_7.data_symbols; i++) aMSC_7.distribution_forbidden[i] = aMSC_7.symbol_count[i]; aMSC_7.pre_count = aMSC_7.total_count;
	for (int i = 0; i < aMSC_8.data_symbols; i++) aMSC_8.distribution_forbidden[i] = aMSC_8.symbol_count[i]; aMSC_8.pre_count = aMSC_8.total_count;
	for (int i = 0; i < aMSC_00.data_symbols; i++) aMSC_00.distribution_forbidden[i] = aMSC_00.symbol_count[i]; aMSC_00.pre_count = aMSC_00.total_count;
	for (int i = 0; i < aMSC_01.data_symbols; i++) aMSC_01.distribution_forbidden[i] = aMSC_01.symbol_count[i]; aMSC_01.pre_count = aMSC_01.total_count;
	for (int i = 0; i < aMSC_02.data_symbols; i++) aMSC_02.distribution_forbidden[i] = aMSC_02.symbol_count[i]; aMSC_02.pre_count = aMSC_02.total_count;
	for (int i = 0; i < aMSC_03.data_symbols; i++) aMSC_03.distribution_forbidden[i] = aMSC_03.symbol_count[i]; aMSC_03.pre_count = aMSC_03.total_count;
	for (int i = 0; i < aMSC_04.data_symbols; i++) aMSC_04.distribution_forbidden[i] = aMSC_04.symbol_count[i]; aMSC_04.pre_count = aMSC_04.total_count;
	for (int i = 0; i < aMSC_05.data_symbols; i++) aMSC_05.distribution_forbidden[i] = aMSC_05.symbol_count[i]; aMSC_05.pre_count = aMSC_05.total_count;
	for (int i = 0; i < aMSC_06.data_symbols; i++) aMSC_06.distribution_forbidden[i] = aMSC_06.symbol_count[i]; aMSC_06.pre_count = aMSC_06.total_count;
	for (int i = 0; i < aMSC_07.data_symbols; i++) aMSC_07.distribution_forbidden[i] = aMSC_07.symbol_count[i]; aMSC_07.pre_count = aMSC_07.total_count;
	for (int i = 0; i < aMSC_08.data_symbols; i++) aMSC_08.distribution_forbidden[i] = aMSC_08.symbol_count[i]; aMSC_08.pre_count = aMSC_08.total_count;
	for (int i = 0; i < aMSC_09.data_symbols; i++) aMSC_09.distribution_forbidden[i] = aMSC_09.symbol_count[i]; aMSC_09.pre_count = aMSC_09.total_count;
	for (int i = 0; i < aMSC_010.data_symbols; i++) aMSC_010.distribution_forbidden[i] = aMSC_010.symbol_count[i]; aMSC_010.pre_count = aMSC_010.total_count;
	for (int i = 0; i < aMSC_011.data_symbols; i++) aMSC_011.distribution_forbidden[i] = aMSC_011.symbol_count[i]; aMSC_011.pre_count = aMSC_011.total_count;
	for (int i = 0; i < aMSC_012.data_symbols; i++) aMSC_012.distribution_forbidden[i] = aMSC_012.symbol_count[i]; aMSC_012.pre_count = aMSC_012.total_count;
	for (int i = 0; i < aMSC_013.data_symbols; i++) aMSC_013.distribution_forbidden[i] = aMSC_013.symbol_count[i]; aMSC_013.pre_count = aMSC_013.total_count;
	for (int i = 0; i < aMSC_014.data_symbols; i++) aMSC_014.distribution_forbidden[i] = aMSC_014.symbol_count[i]; aMSC_014.pre_count = aMSC_014.total_count;
	for (int i = 0; i < aMSC_015.data_symbols; i++) aMSC_015.distribution_forbidden[i] = aMSC_015.symbol_count[i]; aMSC_015.pre_count = aMSC_015.total_count;
	for (int i = 0; i < aMSC_016.data_symbols; i++) aMSC_016.distribution_forbidden[i] = aMSC_016.symbol_count[i]; aMSC_016.pre_count = aMSC_016.total_count;
	for (int i = 0; i < aMSC_017.data_symbols; i++) aMSC_017.distribution_forbidden[i] = aMSC_017.symbol_count[i]; aMSC_017.pre_count = aMSC_017.total_count;
	for (int i = 0; i < aMSC_018.data_symbols; i++) aMSC_018.distribution_forbidden[i] = aMSC_018.symbol_count[i]; aMSC_018.pre_count = aMSC_018.total_count;
	for (int i = 0; i < aMSC_019.data_symbols; i++) aMSC_019.distribution_forbidden[i] = aMSC_019.symbol_count[i]; aMSC_019.pre_count = aMSC_019.total_count;
	for (int i = 0; i < aMSC_020.data_symbols; i++) aMSC_020.distribution_forbidden[i] = aMSC_020.symbol_count[i]; aMSC_020.pre_count = aMSC_020.total_count;
	for (int i = 0; i < aMSC_021.data_symbols; i++) aMSC_021.distribution_forbidden[i] = aMSC_021.symbol_count[i]; aMSC_021.pre_count = aMSC_021.total_count;
	for (int i = 0; i < aMSC_022.data_symbols; i++) aMSC_022.distribution_forbidden[i] = aMSC_022.symbol_count[i]; aMSC_022.pre_count = aMSC_022.total_count;
	for (int i = 0; i < aMSC_023.data_symbols; i++) aMSC_023.distribution_forbidden[i] = aMSC_023.symbol_count[i]; aMSC_023.pre_count = aMSC_023.total_count;
	for (int i = 0; i < aMSC_024.data_symbols; i++) aMSC_024.distribution_forbidden[i] = aMSC_024.symbol_count[i]; aMSC_024.pre_count = aMSC_024.total_count;
	for (int i = 0; i < aMSC_025.data_symbols; i++) aMSC_025.distribution_forbidden[i] = aMSC_025.symbol_count[i]; aMSC_025.pre_count = aMSC_025.total_count;
	for (int i = 0; i < aMSC_026.data_symbols; i++) aMSC_026.distribution_forbidden[i] = aMSC_026.symbol_count[i]; aMSC_026.pre_count = aMSC_026.total_count;
	for (int i = 0; i < aMSC_10.data_symbols; i++) aMSC_10.distribution_forbidden[i] = aMSC_10.symbol_count[i]; aMSC_10.pre_count = aMSC_10.total_count;
	for (int i = 0; i < aMSC_11.data_symbols; i++) aMSC_11.distribution_forbidden[i] = aMSC_11.symbol_count[i]; aMSC_11.pre_count = aMSC_11.total_count;
	for (int i = 0; i < aMSC_12.data_symbols; i++) aMSC_12.distribution_forbidden[i] = aMSC_12.symbol_count[i]; aMSC_12.pre_count = aMSC_12.total_count;
	for (int i = 0; i < aMSC_13.data_symbols; i++) aMSC_13.distribution_forbidden[i] = aMSC_13.symbol_count[i]; aMSC_13.pre_count = aMSC_13.total_count;
	for (int i = 0; i < aMSC_14.data_symbols; i++) aMSC_14.distribution_forbidden[i] = aMSC_14.symbol_count[i]; aMSC_14.pre_count = aMSC_14.total_count;
	for (int i = 0; i < aMSC_15.data_symbols; i++) aMSC_15.distribution_forbidden[i] = aMSC_15.symbol_count[i]; aMSC_15.pre_count = aMSC_15.total_count;
	for (int i = 0; i < aMSC_16.data_symbols; i++) aMSC_16.distribution_forbidden[i] = aMSC_16.symbol_count[i]; aMSC_16.pre_count = aMSC_16.total_count;
	for (int i = 0; i < aMSC_17.data_symbols; i++) aMSC_17.distribution_forbidden[i] = aMSC_17.symbol_count[i]; aMSC_17.pre_count = aMSC_17.total_count;
	for (int i = 0; i < aMSC_18.data_symbols; i++) aMSC_18.distribution_forbidden[i] = aMSC_18.symbol_count[i]; aMSC_18.pre_count = aMSC_18.total_count;
	for (int i = 0; i < aMSC_19.data_symbols; i++) aMSC_19.distribution_forbidden[i] = aMSC_19.symbol_count[i]; aMSC_19.pre_count = aMSC_19.total_count;
	for (int i = 0; i < aMSC_110.data_symbols; i++) aMSC_110.distribution_forbidden[i] = aMSC_110.symbol_count[i]; aMSC_110.pre_count = aMSC_110.total_count;
	for (int i = 0; i < aMSC_111.data_symbols; i++) aMSC_111.distribution_forbidden[i] = aMSC_111.symbol_count[i]; aMSC_111.pre_count = aMSC_111.total_count;
	for (int i = 0; i < aMSC_112.data_symbols; i++) aMSC_112.distribution_forbidden[i] = aMSC_112.symbol_count[i]; aMSC_112.pre_count = aMSC_112.total_count;
	for (int i = 0; i < aMSC_113.data_symbols; i++) aMSC_113.distribution_forbidden[i] = aMSC_113.symbol_count[i]; aMSC_113.pre_count = aMSC_113.total_count;
	for (int i = 0; i < aMSC_114.data_symbols; i++) aMSC_114.distribution_forbidden[i] = aMSC_114.symbol_count[i]; aMSC_114.pre_count = aMSC_114.total_count;
	for (int i = 0; i < aMSC_115.data_symbols; i++) aMSC_115.distribution_forbidden[i] = aMSC_115.symbol_count[i]; aMSC_115.pre_count = aMSC_115.total_count;
	for (int i = 0; i < aMSC_116.data_symbols; i++) aMSC_116.distribution_forbidden[i] = aMSC_116.symbol_count[i]; aMSC_116.pre_count = aMSC_116.total_count;
	for (int i = 0; i < aMSC_117.data_symbols; i++) aMSC_117.distribution_forbidden[i] = aMSC_117.symbol_count[i]; aMSC_117.pre_count = aMSC_117.total_count;
	for (int i = 0; i < aMSC_118.data_symbols; i++) aMSC_118.distribution_forbidden[i] = aMSC_118.symbol_count[i]; aMSC_118.pre_count = aMSC_118.total_count;
	for (int i = 0; i < aMSC_119.data_symbols; i++) aMSC_119.distribution_forbidden[i] = aMSC_119.symbol_count[i]; aMSC_119.pre_count = aMSC_119.total_count;
	for (int i = 0; i < aMSC_120.data_symbols; i++) aMSC_120.distribution_forbidden[i] = aMSC_120.symbol_count[i]; aMSC_120.pre_count = aMSC_120.total_count;
	for (int i = 0; i < aMSC_121.data_symbols; i++) aMSC_121.distribution_forbidden[i] = aMSC_121.symbol_count[i]; aMSC_121.pre_count = aMSC_121.total_count;
	for (int i = 0; i < aMSC_122.data_symbols; i++) aMSC_122.distribution_forbidden[i] = aMSC_122.symbol_count[i]; aMSC_122.pre_count = aMSC_122.total_count;
	for (int i = 0; i < aMSC_123.data_symbols; i++) aMSC_123.distribution_forbidden[i] = aMSC_123.symbol_count[i]; aMSC_123.pre_count = aMSC_123.total_count;
	for (int i = 0; i < aMSC_124.data_symbols; i++) aMSC_124.distribution_forbidden[i] = aMSC_124.symbol_count[i]; aMSC_124.pre_count = aMSC_124.total_count;
	for (int i = 0; i < aMSC_125.data_symbols; i++) aMSC_125.distribution_forbidden[i] = aMSC_125.symbol_count[i]; aMSC_125.pre_count = aMSC_125.total_count;
	for (int i = 0; i < aMSC_126.data_symbols; i++) aMSC_126.distribution_forbidden[i] = aMSC_126.symbol_count[i]; aMSC_126.pre_count = aMSC_126.total_count;
	for (int i = 0; i < aMSC_20.data_symbols; i++) aMSC_20.distribution_forbidden[i] = aMSC_20.symbol_count[i]; aMSC_20.pre_count = aMSC_20.total_count;
	for (int i = 0; i < aMSC_21.data_symbols; i++) aMSC_21.distribution_forbidden[i] = aMSC_21.symbol_count[i]; aMSC_21.pre_count = aMSC_21.total_count;
	for (int i = 0; i < aMSC_22.data_symbols; i++) aMSC_22.distribution_forbidden[i] = aMSC_22.symbol_count[i]; aMSC_22.pre_count = aMSC_22.total_count;
	for (int i = 0; i < aMSC_23.data_symbols; i++) aMSC_23.distribution_forbidden[i] = aMSC_23.symbol_count[i]; aMSC_23.pre_count = aMSC_23.total_count;
	for (int i = 0; i < aMSC_24.data_symbols; i++) aMSC_24.distribution_forbidden[i] = aMSC_24.symbol_count[i]; aMSC_24.pre_count = aMSC_24.total_count;
	for (int i = 0; i < aMSC_25.data_symbols; i++) aMSC_25.distribution_forbidden[i] = aMSC_25.symbol_count[i]; aMSC_25.pre_count = aMSC_25.total_count;
	for (int i = 0; i < aMSC_26.data_symbols; i++) aMSC_26.distribution_forbidden[i] = aMSC_26.symbol_count[i]; aMSC_26.pre_count = aMSC_26.total_count;
	for (int i = 0; i < aMSC_27.data_symbols; i++) aMSC_27.distribution_forbidden[i] = aMSC_27.symbol_count[i]; aMSC_27.pre_count = aMSC_27.total_count;
	for (int i = 0; i < aMSC_28.data_symbols; i++) aMSC_28.distribution_forbidden[i] = aMSC_28.symbol_count[i]; aMSC_28.pre_count = aMSC_28.total_count;
	for (int i = 0; i < aMSC_29.data_symbols; i++) aMSC_29.distribution_forbidden[i] = aMSC_29.symbol_count[i]; aMSC_29.pre_count = aMSC_29.total_count;
	for (int i = 0; i < aMSC_210.data_symbols; i++) aMSC_210.distribution_forbidden[i] = aMSC_210.symbol_count[i]; aMSC_210.pre_count = aMSC_210.total_count;
	for (int i = 0; i < aMSC_211.data_symbols; i++) aMSC_211.distribution_forbidden[i] = aMSC_211.symbol_count[i]; aMSC_211.pre_count = aMSC_211.total_count;
	for (int i = 0; i < aMSC_212.data_symbols; i++) aMSC_212.distribution_forbidden[i] = aMSC_212.symbol_count[i]; aMSC_212.pre_count = aMSC_212.total_count;
	for (int i = 0; i < aMSC_213.data_symbols; i++) aMSC_213.distribution_forbidden[i] = aMSC_213.symbol_count[i]; aMSC_213.pre_count = aMSC_213.total_count;
	for (int i = 0; i < aMSC_214.data_symbols; i++) aMSC_214.distribution_forbidden[i] = aMSC_214.symbol_count[i]; aMSC_214.pre_count = aMSC_214.total_count;
	for (int i = 0; i < aMSC_215.data_symbols; i++) aMSC_215.distribution_forbidden[i] = aMSC_215.symbol_count[i]; aMSC_215.pre_count = aMSC_215.total_count;
	for (int i = 0; i < aMSC_216.data_symbols; i++) aMSC_216.distribution_forbidden[i] = aMSC_216.symbol_count[i]; aMSC_216.pre_count = aMSC_216.total_count;
	for (int i = 0; i < aMSC_217.data_symbols; i++) aMSC_217.distribution_forbidden[i] = aMSC_217.symbol_count[i]; aMSC_217.pre_count = aMSC_217.total_count;
	for (int i = 0; i < aMSC_218.data_symbols; i++) aMSC_218.distribution_forbidden[i] = aMSC_218.symbol_count[i]; aMSC_218.pre_count = aMSC_218.total_count;
	for (int i = 0; i < aMSC_219.data_symbols; i++) aMSC_219.distribution_forbidden[i] = aMSC_219.symbol_count[i]; aMSC_219.pre_count = aMSC_219.total_count;
	for (int i = 0; i < aMSC_220.data_symbols; i++) aMSC_220.distribution_forbidden[i] = aMSC_220.symbol_count[i]; aMSC_220.pre_count = aMSC_220.total_count;
	for (int i = 0; i < aMSC_221.data_symbols; i++) aMSC_221.distribution_forbidden[i] = aMSC_221.symbol_count[i]; aMSC_221.pre_count = aMSC_221.total_count;
	for (int i = 0; i < aMSC_222.data_symbols; i++) aMSC_222.distribution_forbidden[i] = aMSC_222.symbol_count[i]; aMSC_222.pre_count = aMSC_222.total_count;
	for (int i = 0; i < aMSC_223.data_symbols; i++) aMSC_223.distribution_forbidden[i] = aMSC_223.symbol_count[i]; aMSC_223.pre_count = aMSC_223.total_count;
	for (int i = 0; i < aMSC_224.data_symbols; i++) aMSC_224.distribution_forbidden[i] = aMSC_224.symbol_count[i]; aMSC_224.pre_count = aMSC_224.total_count;
	for (int i = 0; i < aMSC_225.data_symbols; i++) aMSC_225.distribution_forbidden[i] = aMSC_225.symbol_count[i]; aMSC_225.pre_count = aMSC_225.total_count;
	for (int i = 0; i < aMSC_226.data_symbols; i++) aMSC_226.distribution_forbidden[i] = aMSC_226.symbol_count[i]; aMSC_226.pre_count = aMSC_226.total_count;
	for (int i = 0; i < aMSC_30.data_symbols; i++) aMSC_30.distribution_forbidden[i] = aMSC_30.symbol_count[i]; aMSC_30.pre_count = aMSC_30.total_count;
	for (int i = 0; i < aMSC_31.data_symbols; i++) aMSC_31.distribution_forbidden[i] = aMSC_31.symbol_count[i]; aMSC_31.pre_count = aMSC_31.total_count;
	for (int i = 0; i < aMSC_32.data_symbols; i++) aMSC_32.distribution_forbidden[i] = aMSC_32.symbol_count[i]; aMSC_32.pre_count = aMSC_32.total_count;
	for (int i = 0; i < aMSC_33.data_symbols; i++) aMSC_33.distribution_forbidden[i] = aMSC_33.symbol_count[i]; aMSC_33.pre_count = aMSC_33.total_count;
	for (int i = 0; i < aMSC_34.data_symbols; i++) aMSC_34.distribution_forbidden[i] = aMSC_34.symbol_count[i]; aMSC_34.pre_count = aMSC_34.total_count;
	for (int i = 0; i < aMSC_35.data_symbols; i++) aMSC_35.distribution_forbidden[i] = aMSC_35.symbol_count[i]; aMSC_35.pre_count = aMSC_35.total_count;
	for (int i = 0; i < aMSC_36.data_symbols; i++) aMSC_36.distribution_forbidden[i] = aMSC_36.symbol_count[i]; aMSC_36.pre_count = aMSC_36.total_count;
	for (int i = 0; i < aMSC_37.data_symbols; i++) aMSC_37.distribution_forbidden[i] = aMSC_37.symbol_count[i]; aMSC_37.pre_count = aMSC_37.total_count;
	for (int i = 0; i < aMSC_38.data_symbols; i++) aMSC_38.distribution_forbidden[i] = aMSC_38.symbol_count[i]; aMSC_38.pre_count = aMSC_38.total_count;
	for (int i = 0; i < aMSC_39.data_symbols; i++) aMSC_39.distribution_forbidden[i] = aMSC_39.symbol_count[i]; aMSC_39.pre_count = aMSC_39.total_count;
	for (int i = 0; i < aMSC_310.data_symbols; i++) aMSC_310.distribution_forbidden[i] = aMSC_310.symbol_count[i]; aMSC_310.pre_count = aMSC_310.total_count;
	for (int i = 0; i < aMSC_311.data_symbols; i++) aMSC_311.distribution_forbidden[i] = aMSC_311.symbol_count[i]; aMSC_311.pre_count = aMSC_311.total_count;
	for (int i = 0; i < aMSC_312.data_symbols; i++) aMSC_312.distribution_forbidden[i] = aMSC_312.symbol_count[i]; aMSC_312.pre_count = aMSC_312.total_count;
	for (int i = 0; i < aMSC_313.data_symbols; i++) aMSC_313.distribution_forbidden[i] = aMSC_313.symbol_count[i]; aMSC_313.pre_count = aMSC_313.total_count;
	for (int i = 0; i < aMSC_314.data_symbols; i++) aMSC_314.distribution_forbidden[i] = aMSC_314.symbol_count[i]; aMSC_314.pre_count = aMSC_314.total_count;
	for (int i = 0; i < aMSC_315.data_symbols; i++) aMSC_315.distribution_forbidden[i] = aMSC_315.symbol_count[i]; aMSC_315.pre_count = aMSC_315.total_count;
	for (int i = 0; i < aMSC_316.data_symbols; i++) aMSC_316.distribution_forbidden[i] = aMSC_316.symbol_count[i]; aMSC_316.pre_count = aMSC_316.total_count;
	for (int i = 0; i < aMSC_317.data_symbols; i++) aMSC_317.distribution_forbidden[i] = aMSC_317.symbol_count[i]; aMSC_317.pre_count = aMSC_317.total_count;
	for (int i = 0; i < aMSC_318.data_symbols; i++) aMSC_318.distribution_forbidden[i] = aMSC_318.symbol_count[i]; aMSC_318.pre_count = aMSC_318.total_count;
	for (int i = 0; i < aMSC_319.data_symbols; i++) aMSC_319.distribution_forbidden[i] = aMSC_319.symbol_count[i]; aMSC_319.pre_count = aMSC_319.total_count;
	for (int i = 0; i < aMSC_320.data_symbols; i++) aMSC_320.distribution_forbidden[i] = aMSC_320.symbol_count[i]; aMSC_320.pre_count = aMSC_320.total_count;
	for (int i = 0; i < aMSC_321.data_symbols; i++) aMSC_321.distribution_forbidden[i] = aMSC_321.symbol_count[i]; aMSC_321.pre_count = aMSC_321.total_count;
	for (int i = 0; i < aMSC_322.data_symbols; i++) aMSC_322.distribution_forbidden[i] = aMSC_322.symbol_count[i]; aMSC_322.pre_count = aMSC_322.total_count;
	for (int i = 0; i < aMSC_323.data_symbols; i++) aMSC_323.distribution_forbidden[i] = aMSC_323.symbol_count[i]; aMSC_323.pre_count = aMSC_323.total_count;
	for (int i = 0; i < aMSC_324.data_symbols; i++) aMSC_324.distribution_forbidden[i] = aMSC_324.symbol_count[i]; aMSC_324.pre_count = aMSC_324.total_count;
	for (int i = 0; i < aMSC_325.data_symbols; i++) aMSC_325.distribution_forbidden[i] = aMSC_325.symbol_count[i]; aMSC_325.pre_count = aMSC_325.total_count;
	for (int i = 0; i < aMSC_326.data_symbols; i++) aMSC_326.distribution_forbidden[i] = aMSC_326.symbol_count[i]; aMSC_326.pre_count = aMSC_326.total_count;
	for (int i = 0; i < aMSC_40.data_symbols; i++) aMSC_40.distribution_forbidden[i] = aMSC_40.symbol_count[i]; aMSC_40.pre_count = aMSC_40.total_count;
	for (int i = 0; i < aMSC_41.data_symbols; i++) aMSC_41.distribution_forbidden[i] = aMSC_41.symbol_count[i]; aMSC_41.pre_count = aMSC_41.total_count;
	for (int i = 0; i < aMSC_42.data_symbols; i++) aMSC_42.distribution_forbidden[i] = aMSC_42.symbol_count[i]; aMSC_42.pre_count = aMSC_42.total_count;
	for (int i = 0; i < aMSC_43.data_symbols; i++) aMSC_43.distribution_forbidden[i] = aMSC_43.symbol_count[i]; aMSC_43.pre_count = aMSC_43.total_count;
	for (int i = 0; i < aMSC_44.data_symbols; i++) aMSC_44.distribution_forbidden[i] = aMSC_44.symbol_count[i]; aMSC_44.pre_count = aMSC_44.total_count;
	for (int i = 0; i < aMSC_45.data_symbols; i++) aMSC_45.distribution_forbidden[i] = aMSC_45.symbol_count[i]; aMSC_45.pre_count = aMSC_45.total_count;
	for (int i = 0; i < aMSC_46.data_symbols; i++) aMSC_46.distribution_forbidden[i] = aMSC_46.symbol_count[i]; aMSC_46.pre_count = aMSC_46.total_count;
	for (int i = 0; i < aMSC_47.data_symbols; i++) aMSC_47.distribution_forbidden[i] = aMSC_47.symbol_count[i]; aMSC_47.pre_count = aMSC_47.total_count;
	for (int i = 0; i < aMSC_48.data_symbols; i++) aMSC_48.distribution_forbidden[i] = aMSC_48.symbol_count[i]; aMSC_48.pre_count = aMSC_48.total_count;
	for (int i = 0; i < aMSC_49.data_symbols; i++) aMSC_49.distribution_forbidden[i] = aMSC_49.symbol_count[i]; aMSC_49.pre_count = aMSC_49.total_count;
	for (int i = 0; i < aMSC_410.data_symbols; i++) aMSC_410.distribution_forbidden[i] = aMSC_410.symbol_count[i]; aMSC_410.pre_count = aMSC_410.total_count;
	for (int i = 0; i < aMSC_411.data_symbols; i++) aMSC_411.distribution_forbidden[i] = aMSC_411.symbol_count[i]; aMSC_411.pre_count = aMSC_411.total_count;
	for (int i = 0; i < aMSC_412.data_symbols; i++) aMSC_412.distribution_forbidden[i] = aMSC_412.symbol_count[i]; aMSC_412.pre_count = aMSC_412.total_count;
	for (int i = 0; i < aMSC_413.data_symbols; i++) aMSC_413.distribution_forbidden[i] = aMSC_413.symbol_count[i]; aMSC_413.pre_count = aMSC_413.total_count;
	for (int i = 0; i < aMSC_414.data_symbols; i++) aMSC_414.distribution_forbidden[i] = aMSC_414.symbol_count[i]; aMSC_414.pre_count = aMSC_414.total_count;
	for (int i = 0; i < aMSC_415.data_symbols; i++) aMSC_415.distribution_forbidden[i] = aMSC_415.symbol_count[i]; aMSC_415.pre_count = aMSC_415.total_count;
	for (int i = 0; i < aMSC_416.data_symbols; i++) aMSC_416.distribution_forbidden[i] = aMSC_416.symbol_count[i]; aMSC_416.pre_count = aMSC_416.total_count;
	for (int i = 0; i < aMSC_417.data_symbols; i++) aMSC_417.distribution_forbidden[i] = aMSC_417.symbol_count[i]; aMSC_417.pre_count = aMSC_417.total_count;
	for (int i = 0; i < aMSC_418.data_symbols; i++) aMSC_418.distribution_forbidden[i] = aMSC_418.symbol_count[i]; aMSC_418.pre_count = aMSC_418.total_count;
	for (int i = 0; i < aMSC_419.data_symbols; i++) aMSC_419.distribution_forbidden[i] = aMSC_419.symbol_count[i]; aMSC_419.pre_count = aMSC_419.total_count;
	for (int i = 0; i < aMSC_420.data_symbols; i++) aMSC_420.distribution_forbidden[i] = aMSC_420.symbol_count[i]; aMSC_420.pre_count = aMSC_420.total_count;
	for (int i = 0; i < aMSC_421.data_symbols; i++) aMSC_421.distribution_forbidden[i] = aMSC_421.symbol_count[i]; aMSC_421.pre_count = aMSC_421.total_count;
	for (int i = 0; i < aMSC_422.data_symbols; i++) aMSC_422.distribution_forbidden[i] = aMSC_422.symbol_count[i]; aMSC_422.pre_count = aMSC_422.total_count;
	for (int i = 0; i < aMSC_423.data_symbols; i++) aMSC_423.distribution_forbidden[i] = aMSC_423.symbol_count[i]; aMSC_423.pre_count = aMSC_423.total_count;
	for (int i = 0; i < aMSC_424.data_symbols; i++) aMSC_424.distribution_forbidden[i] = aMSC_424.symbol_count[i]; aMSC_424.pre_count = aMSC_424.total_count;
	for (int i = 0; i < aMSC_425.data_symbols; i++) aMSC_425.distribution_forbidden[i] = aMSC_425.symbol_count[i]; aMSC_425.pre_count = aMSC_425.total_count;
	for (int i = 0; i < aMSC_426.data_symbols; i++) aMSC_426.distribution_forbidden[i] = aMSC_426.symbol_count[i]; aMSC_426.pre_count = aMSC_426.total_count;
	for (int i = 0; i < aMSC_50.data_symbols; i++) aMSC_50.distribution_forbidden[i] = aMSC_50.symbol_count[i]; aMSC_50.pre_count = aMSC_50.total_count;
	for (int i = 0; i < aMSC_51.data_symbols; i++) aMSC_51.distribution_forbidden[i] = aMSC_51.symbol_count[i]; aMSC_51.pre_count = aMSC_51.total_count;
	for (int i = 0; i < aMSC_52.data_symbols; i++) aMSC_52.distribution_forbidden[i] = aMSC_52.symbol_count[i]; aMSC_52.pre_count = aMSC_52.total_count;
	for (int i = 0; i < aMSC_53.data_symbols; i++) aMSC_53.distribution_forbidden[i] = aMSC_53.symbol_count[i]; aMSC_53.pre_count = aMSC_53.total_count;
	for (int i = 0; i < aMSC_54.data_symbols; i++) aMSC_54.distribution_forbidden[i] = aMSC_54.symbol_count[i]; aMSC_54.pre_count = aMSC_54.total_count;
	for (int i = 0; i < aMSC_55.data_symbols; i++) aMSC_55.distribution_forbidden[i] = aMSC_55.symbol_count[i]; aMSC_55.pre_count = aMSC_55.total_count;
	for (int i = 0; i < aMSC_56.data_symbols; i++) aMSC_56.distribution_forbidden[i] = aMSC_56.symbol_count[i]; aMSC_56.pre_count = aMSC_56.total_count;
	for (int i = 0; i < aMSC_57.data_symbols; i++) aMSC_57.distribution_forbidden[i] = aMSC_57.symbol_count[i]; aMSC_57.pre_count = aMSC_57.total_count;
	for (int i = 0; i < aMSC_58.data_symbols; i++) aMSC_58.distribution_forbidden[i] = aMSC_58.symbol_count[i]; aMSC_58.pre_count = aMSC_58.total_count;
	for (int i = 0; i < aMSC_59.data_symbols; i++) aMSC_59.distribution_forbidden[i] = aMSC_59.symbol_count[i]; aMSC_59.pre_count = aMSC_59.total_count;
	for (int i = 0; i < aMSC_510.data_symbols; i++) aMSC_510.distribution_forbidden[i] = aMSC_510.symbol_count[i]; aMSC_510.pre_count = aMSC_510.total_count;
	for (int i = 0; i < aMSC_511.data_symbols; i++) aMSC_511.distribution_forbidden[i] = aMSC_511.symbol_count[i]; aMSC_511.pre_count = aMSC_511.total_count;
	for (int i = 0; i < aMSC_512.data_symbols; i++) aMSC_512.distribution_forbidden[i] = aMSC_512.symbol_count[i]; aMSC_512.pre_count = aMSC_512.total_count;
	for (int i = 0; i < aMSC_513.data_symbols; i++) aMSC_513.distribution_forbidden[i] = aMSC_513.symbol_count[i]; aMSC_513.pre_count = aMSC_513.total_count;
	for (int i = 0; i < aMSC_514.data_symbols; i++) aMSC_514.distribution_forbidden[i] = aMSC_514.symbol_count[i]; aMSC_514.pre_count = aMSC_514.total_count;
	for (int i = 0; i < aMSC_515.data_symbols; i++) aMSC_515.distribution_forbidden[i] = aMSC_515.symbol_count[i]; aMSC_515.pre_count = aMSC_515.total_count;
	for (int i = 0; i < aMSC_516.data_symbols; i++) aMSC_516.distribution_forbidden[i] = aMSC_516.symbol_count[i]; aMSC_516.pre_count = aMSC_516.total_count;
	for (int i = 0; i < aMSC_517.data_symbols; i++) aMSC_517.distribution_forbidden[i] = aMSC_517.symbol_count[i]; aMSC_517.pre_count = aMSC_517.total_count;
	for (int i = 0; i < aMSC_518.data_symbols; i++) aMSC_518.distribution_forbidden[i] = aMSC_518.symbol_count[i]; aMSC_518.pre_count = aMSC_518.total_count;
	for (int i = 0; i < aMSC_519.data_symbols; i++) aMSC_519.distribution_forbidden[i] = aMSC_519.symbol_count[i]; aMSC_519.pre_count = aMSC_519.total_count;
	for (int i = 0; i < aMSC_520.data_symbols; i++) aMSC_520.distribution_forbidden[i] = aMSC_520.symbol_count[i]; aMSC_520.pre_count = aMSC_520.total_count;
	for (int i = 0; i < aMSC_521.data_symbols; i++) aMSC_521.distribution_forbidden[i] = aMSC_521.symbol_count[i]; aMSC_521.pre_count = aMSC_521.total_count;
	for (int i = 0; i < aMSC_522.data_symbols; i++) aMSC_522.distribution_forbidden[i] = aMSC_522.symbol_count[i]; aMSC_522.pre_count = aMSC_522.total_count;
	for (int i = 0; i < aMSC_523.data_symbols; i++) aMSC_523.distribution_forbidden[i] = aMSC_523.symbol_count[i]; aMSC_523.pre_count = aMSC_523.total_count;
	for (int i = 0; i < aMSC_524.data_symbols; i++) aMSC_524.distribution_forbidden[i] = aMSC_524.symbol_count[i]; aMSC_524.pre_count = aMSC_524.total_count;
	for (int i = 0; i < aMSC_525.data_symbols; i++) aMSC_525.distribution_forbidden[i] = aMSC_525.symbol_count[i]; aMSC_525.pre_count = aMSC_525.total_count;
	for (int i = 0; i < aMSC_526.data_symbols; i++) aMSC_526.distribution_forbidden[i] = aMSC_526.symbol_count[i]; aMSC_526.pre_count = aMSC_526.total_count;
	for (int i = 0; i < aMSC_60.data_symbols; i++) aMSC_60.distribution_forbidden[i] = aMSC_60.symbol_count[i]; aMSC_60.pre_count = aMSC_60.total_count;
	for (int i = 0; i < aMSC_61.data_symbols; i++) aMSC_61.distribution_forbidden[i] = aMSC_61.symbol_count[i]; aMSC_61.pre_count = aMSC_61.total_count;
	for (int i = 0; i < aMSC_62.data_symbols; i++) aMSC_62.distribution_forbidden[i] = aMSC_62.symbol_count[i]; aMSC_62.pre_count = aMSC_62.total_count;
	for (int i = 0; i < aMSC_63.data_symbols; i++) aMSC_63.distribution_forbidden[i] = aMSC_63.symbol_count[i]; aMSC_63.pre_count = aMSC_63.total_count;
	for (int i = 0; i < aMSC_64.data_symbols; i++) aMSC_64.distribution_forbidden[i] = aMSC_64.symbol_count[i]; aMSC_64.pre_count = aMSC_64.total_count;
	for (int i = 0; i < aMSC_65.data_symbols; i++) aMSC_65.distribution_forbidden[i] = aMSC_65.symbol_count[i]; aMSC_65.pre_count = aMSC_65.total_count;
	for (int i = 0; i < aMSC_66.data_symbols; i++) aMSC_66.distribution_forbidden[i] = aMSC_66.symbol_count[i]; aMSC_66.pre_count = aMSC_66.total_count;
	for (int i = 0; i < aMSC_67.data_symbols; i++) aMSC_67.distribution_forbidden[i] = aMSC_67.symbol_count[i]; aMSC_67.pre_count = aMSC_67.total_count;
	for (int i = 0; i < aMSC_68.data_symbols; i++) aMSC_68.distribution_forbidden[i] = aMSC_68.symbol_count[i]; aMSC_68.pre_count = aMSC_68.total_count;
	for (int i = 0; i < aMSC_69.data_symbols; i++) aMSC_69.distribution_forbidden[i] = aMSC_69.symbol_count[i]; aMSC_69.pre_count = aMSC_69.total_count;
	for (int i = 0; i < aMSC_610.data_symbols; i++) aMSC_610.distribution_forbidden[i] = aMSC_610.symbol_count[i]; aMSC_610.pre_count = aMSC_610.total_count;
	for (int i = 0; i < aMSC_611.data_symbols; i++) aMSC_611.distribution_forbidden[i] = aMSC_611.symbol_count[i]; aMSC_611.pre_count = aMSC_611.total_count;
	for (int i = 0; i < aMSC_612.data_symbols; i++) aMSC_612.distribution_forbidden[i] = aMSC_612.symbol_count[i]; aMSC_612.pre_count = aMSC_612.total_count;
	for (int i = 0; i < aMSC_613.data_symbols; i++) aMSC_613.distribution_forbidden[i] = aMSC_613.symbol_count[i]; aMSC_613.pre_count = aMSC_613.total_count;
	for (int i = 0; i < aMSC_614.data_symbols; i++) aMSC_614.distribution_forbidden[i] = aMSC_614.symbol_count[i]; aMSC_614.pre_count = aMSC_614.total_count;
	for (int i = 0; i < aMSC_615.data_symbols; i++) aMSC_615.distribution_forbidden[i] = aMSC_615.symbol_count[i]; aMSC_615.pre_count = aMSC_615.total_count;
	for (int i = 0; i < aMSC_616.data_symbols; i++) aMSC_616.distribution_forbidden[i] = aMSC_616.symbol_count[i]; aMSC_616.pre_count = aMSC_616.total_count;
	for (int i = 0; i < aMSC_617.data_symbols; i++) aMSC_617.distribution_forbidden[i] = aMSC_617.symbol_count[i]; aMSC_617.pre_count = aMSC_617.total_count;
	for (int i = 0; i < aMSC_618.data_symbols; i++) aMSC_618.distribution_forbidden[i] = aMSC_618.symbol_count[i]; aMSC_618.pre_count = aMSC_618.total_count;
	for (int i = 0; i < aMSC_619.data_symbols; i++) aMSC_619.distribution_forbidden[i] = aMSC_619.symbol_count[i]; aMSC_619.pre_count = aMSC_619.total_count;
	for (int i = 0; i < aMSC_620.data_symbols; i++) aMSC_620.distribution_forbidden[i] = aMSC_620.symbol_count[i]; aMSC_620.pre_count = aMSC_620.total_count;
	for (int i = 0; i < aMSC_621.data_symbols; i++) aMSC_621.distribution_forbidden[i] = aMSC_621.symbol_count[i]; aMSC_621.pre_count = aMSC_621.total_count;
	for (int i = 0; i < aMSC_622.data_symbols; i++) aMSC_622.distribution_forbidden[i] = aMSC_622.symbol_count[i]; aMSC_622.pre_count = aMSC_622.total_count;
	for (int i = 0; i < aMSC_623.data_symbols; i++) aMSC_623.distribution_forbidden[i] = aMSC_623.symbol_count[i]; aMSC_623.pre_count = aMSC_623.total_count;
	for (int i = 0; i < aMSC_624.data_symbols; i++) aMSC_624.distribution_forbidden[i] = aMSC_624.symbol_count[i]; aMSC_624.pre_count = aMSC_624.total_count;
	for (int i = 0; i < aMSC_625.data_symbols; i++) aMSC_625.distribution_forbidden[i] = aMSC_625.symbol_count[i]; aMSC_625.pre_count = aMSC_625.total_count;
	for (int i = 0; i < aMSC_626.data_symbols; i++) aMSC_626.distribution_forbidden[i] = aMSC_626.symbol_count[i]; aMSC_626.pre_count = aMSC_626.total_count;
	for (int i = 0; i < aMSC_70.data_symbols; i++) aMSC_70.distribution_forbidden[i] = aMSC_70.symbol_count[i]; aMSC_70.pre_count = aMSC_70.total_count;
	for (int i = 0; i < aMSC_71.data_symbols; i++) aMSC_71.distribution_forbidden[i] = aMSC_71.symbol_count[i]; aMSC_71.pre_count = aMSC_71.total_count;
	for (int i = 0; i < aMSC_72.data_symbols; i++) aMSC_72.distribution_forbidden[i] = aMSC_72.symbol_count[i]; aMSC_72.pre_count = aMSC_72.total_count;
	for (int i = 0; i < aMSC_73.data_symbols; i++) aMSC_73.distribution_forbidden[i] = aMSC_73.symbol_count[i]; aMSC_73.pre_count = aMSC_73.total_count;
	for (int i = 0; i < aMSC_74.data_symbols; i++) aMSC_74.distribution_forbidden[i] = aMSC_74.symbol_count[i]; aMSC_74.pre_count = aMSC_74.total_count;
	for (int i = 0; i < aMSC_75.data_symbols; i++) aMSC_75.distribution_forbidden[i] = aMSC_75.symbol_count[i]; aMSC_75.pre_count = aMSC_75.total_count;
	for (int i = 0; i < aMSC_76.data_symbols; i++) aMSC_76.distribution_forbidden[i] = aMSC_76.symbol_count[i]; aMSC_76.pre_count = aMSC_76.total_count;
	for (int i = 0; i < aMSC_77.data_symbols; i++) aMSC_77.distribution_forbidden[i] = aMSC_77.symbol_count[i]; aMSC_77.pre_count = aMSC_77.total_count;
	for (int i = 0; i < aMSC_78.data_symbols; i++) aMSC_78.distribution_forbidden[i] = aMSC_78.symbol_count[i]; aMSC_78.pre_count = aMSC_78.total_count;
	for (int i = 0; i < aMSC_79.data_symbols; i++) aMSC_79.distribution_forbidden[i] = aMSC_79.symbol_count[i]; aMSC_79.pre_count = aMSC_79.total_count;
	for (int i = 0; i < aMSC_710.data_symbols; i++) aMSC_710.distribution_forbidden[i] = aMSC_710.symbol_count[i]; aMSC_710.pre_count = aMSC_710.total_count;
	for (int i = 0; i < aMSC_711.data_symbols; i++) aMSC_711.distribution_forbidden[i] = aMSC_711.symbol_count[i]; aMSC_711.pre_count = aMSC_711.total_count;
	for (int i = 0; i < aMSC_712.data_symbols; i++) aMSC_712.distribution_forbidden[i] = aMSC_712.symbol_count[i]; aMSC_712.pre_count = aMSC_712.total_count;
	for (int i = 0; i < aMSC_713.data_symbols; i++) aMSC_713.distribution_forbidden[i] = aMSC_713.symbol_count[i]; aMSC_713.pre_count = aMSC_713.total_count;
	for (int i = 0; i < aMSC_714.data_symbols; i++) aMSC_714.distribution_forbidden[i] = aMSC_714.symbol_count[i]; aMSC_714.pre_count = aMSC_714.total_count;
	for (int i = 0; i < aMSC_715.data_symbols; i++) aMSC_715.distribution_forbidden[i] = aMSC_715.symbol_count[i]; aMSC_715.pre_count = aMSC_715.total_count;
	for (int i = 0; i < aMSC_716.data_symbols; i++) aMSC_716.distribution_forbidden[i] = aMSC_716.symbol_count[i]; aMSC_716.pre_count = aMSC_716.total_count;
	for (int i = 0; i < aMSC_717.data_symbols; i++) aMSC_717.distribution_forbidden[i] = aMSC_717.symbol_count[i]; aMSC_717.pre_count = aMSC_717.total_count;
	for (int i = 0; i < aMSC_718.data_symbols; i++) aMSC_718.distribution_forbidden[i] = aMSC_718.symbol_count[i]; aMSC_718.pre_count = aMSC_718.total_count;
	for (int i = 0; i < aMSC_719.data_symbols; i++) aMSC_719.distribution_forbidden[i] = aMSC_719.symbol_count[i]; aMSC_719.pre_count = aMSC_719.total_count;
	for (int i = 0; i < aMSC_720.data_symbols; i++) aMSC_720.distribution_forbidden[i] = aMSC_720.symbol_count[i]; aMSC_720.pre_count = aMSC_720.total_count;
	for (int i = 0; i < aMSC_721.data_symbols; i++) aMSC_721.distribution_forbidden[i] = aMSC_721.symbol_count[i]; aMSC_721.pre_count = aMSC_721.total_count;
	for (int i = 0; i < aMSC_722.data_symbols; i++) aMSC_722.distribution_forbidden[i] = aMSC_722.symbol_count[i]; aMSC_722.pre_count = aMSC_722.total_count;
	for (int i = 0; i < aMSC_723.data_symbols; i++) aMSC_723.distribution_forbidden[i] = aMSC_723.symbol_count[i]; aMSC_723.pre_count = aMSC_723.total_count;
	for (int i = 0; i < aMSC_724.data_symbols; i++) aMSC_724.distribution_forbidden[i] = aMSC_724.symbol_count[i]; aMSC_724.pre_count = aMSC_724.total_count;
	for (int i = 0; i < aMSC_725.data_symbols; i++) aMSC_725.distribution_forbidden[i] = aMSC_725.symbol_count[i]; aMSC_725.pre_count = aMSC_725.total_count;
	for (int i = 0; i < aMSC_726.data_symbols; i++) aMSC_726.distribution_forbidden[i] = aMSC_726.symbol_count[i]; aMSC_726.pre_count = aMSC_726.total_count;
	for (int i = 0; i < aMSC_80.data_symbols; i++) aMSC_80.distribution_forbidden[i] = aMSC_80.symbol_count[i]; aMSC_80.pre_count = aMSC_80.total_count;
	for (int i = 0; i < aMSC_81.data_symbols; i++) aMSC_81.distribution_forbidden[i] = aMSC_81.symbol_count[i]; aMSC_81.pre_count = aMSC_81.total_count;
	for (int i = 0; i < aMSC_82.data_symbols; i++) aMSC_82.distribution_forbidden[i] = aMSC_82.symbol_count[i]; aMSC_82.pre_count = aMSC_82.total_count;
	for (int i = 0; i < aMSC_83.data_symbols; i++) aMSC_83.distribution_forbidden[i] = aMSC_83.symbol_count[i]; aMSC_83.pre_count = aMSC_83.total_count;
	for (int i = 0; i < aMSC_84.data_symbols; i++) aMSC_84.distribution_forbidden[i] = aMSC_84.symbol_count[i]; aMSC_84.pre_count = aMSC_84.total_count;
	for (int i = 0; i < aMSC_85.data_symbols; i++) aMSC_85.distribution_forbidden[i] = aMSC_85.symbol_count[i]; aMSC_85.pre_count = aMSC_85.total_count;
	for (int i = 0; i < aMSC_86.data_symbols; i++) aMSC_86.distribution_forbidden[i] = aMSC_86.symbol_count[i]; aMSC_86.pre_count = aMSC_86.total_count;
	for (int i = 0; i < aMSC_87.data_symbols; i++) aMSC_87.distribution_forbidden[i] = aMSC_87.symbol_count[i]; aMSC_87.pre_count = aMSC_87.total_count;
	for (int i = 0; i < aMSC_88.data_symbols; i++) aMSC_88.distribution_forbidden[i] = aMSC_88.symbol_count[i]; aMSC_88.pre_count = aMSC_88.total_count;
	for (int i = 0; i < aMSC_89.data_symbols; i++) aMSC_89.distribution_forbidden[i] = aMSC_89.symbol_count[i]; aMSC_89.pre_count = aMSC_89.total_count;
	for (int i = 0; i < aMSC_810.data_symbols; i++) aMSC_810.distribution_forbidden[i] = aMSC_810.symbol_count[i]; aMSC_810.pre_count = aMSC_810.total_count;
	for (int i = 0; i < aMSC_811.data_symbols; i++) aMSC_811.distribution_forbidden[i] = aMSC_811.symbol_count[i]; aMSC_811.pre_count = aMSC_811.total_count;
	for (int i = 0; i < aMSC_812.data_symbols; i++) aMSC_812.distribution_forbidden[i] = aMSC_812.symbol_count[i]; aMSC_812.pre_count = aMSC_812.total_count;
	for (int i = 0; i < aMSC_813.data_symbols; i++) aMSC_813.distribution_forbidden[i] = aMSC_813.symbol_count[i]; aMSC_813.pre_count = aMSC_813.total_count;
	for (int i = 0; i < aMSC_814.data_symbols; i++) aMSC_814.distribution_forbidden[i] = aMSC_814.symbol_count[i]; aMSC_814.pre_count = aMSC_814.total_count;
	for (int i = 0; i < aMSC_815.data_symbols; i++) aMSC_815.distribution_forbidden[i] = aMSC_815.symbol_count[i]; aMSC_815.pre_count = aMSC_815.total_count;
	for (int i = 0; i < aMSC_816.data_symbols; i++) aMSC_816.distribution_forbidden[i] = aMSC_816.symbol_count[i]; aMSC_816.pre_count = aMSC_816.total_count;
	for (int i = 0; i < aMSC_817.data_symbols; i++) aMSC_817.distribution_forbidden[i] = aMSC_817.symbol_count[i]; aMSC_817.pre_count = aMSC_817.total_count;
	for (int i = 0; i < aMSC_818.data_symbols; i++) aMSC_818.distribution_forbidden[i] = aMSC_818.symbol_count[i]; aMSC_818.pre_count = aMSC_818.total_count;
	for (int i = 0; i < aMSC_819.data_symbols; i++) aMSC_819.distribution_forbidden[i] = aMSC_819.symbol_count[i]; aMSC_819.pre_count = aMSC_819.total_count;
	for (int i = 0; i < aMSC_820.data_symbols; i++) aMSC_820.distribution_forbidden[i] = aMSC_820.symbol_count[i]; aMSC_820.pre_count = aMSC_820.total_count;
	for (int i = 0; i < aMSC_821.data_symbols; i++) aMSC_821.distribution_forbidden[i] = aMSC_821.symbol_count[i]; aMSC_821.pre_count = aMSC_821.total_count;
	for (int i = 0; i < aMSC_822.data_symbols; i++) aMSC_822.distribution_forbidden[i] = aMSC_822.symbol_count[i]; aMSC_822.pre_count = aMSC_822.total_count;
	for (int i = 0; i < aMSC_823.data_symbols; i++) aMSC_823.distribution_forbidden[i] = aMSC_823.symbol_count[i]; aMSC_823.pre_count = aMSC_823.total_count;
	for (int i = 0; i < aMSC_824.data_symbols; i++) aMSC_824.distribution_forbidden[i] = aMSC_824.symbol_count[i]; aMSC_824.pre_count = aMSC_824.total_count;
	for (int i = 0; i < aMSC_825.data_symbols; i++) aMSC_825.distribution_forbidden[i] = aMSC_825.symbol_count[i]; aMSC_825.pre_count = aMSC_825.total_count;
	for (int i = 0; i < aMSC_826.data_symbols; i++) aMSC_826.distribution_forbidden[i] = aMSC_826.symbol_count[i]; aMSC_826.pre_count = aMSC_826.total_count;
}

void restore_MSC()
{
	for (int i = 0; i < aMSC_L.data_symbols; i++) aMSC_L.symbol_count[i] = aMSC_L.distribution_forbidden[i]; aMSC_L.total_count = aMSC_L.pre_count;
	for (int i = 0; i < aMSC_A.data_symbols; i++) aMSC_A.symbol_count[i] = aMSC_A.distribution_forbidden[i]; aMSC_A.total_count = aMSC_A.pre_count;
	for (int i = 0; i < aMSC_B.data_symbols; i++) aMSC_B.symbol_count[i] = aMSC_B.distribution_forbidden[i]; aMSC_B.total_count = aMSC_B.pre_count;
	for (int i = 0; i < aMSC_R.data_symbols; i++) aMSC_R.symbol_count[i] = aMSC_R.distribution_forbidden[i]; aMSC_R.total_count = aMSC_R.pre_count;
	for (int i = 0; i < aMSC_I.data_symbols; i++) aMSC_I.symbol_count[i] = aMSC_I.distribution_forbidden[i]; aMSC_I.total_count = aMSC_I.pre_count;
	for (int i = 0; i < aMSC_0.data_symbols; i++) aMSC_0.symbol_count[i] = aMSC_0.distribution_forbidden[i]; aMSC_0.total_count = aMSC_0.pre_count;
	for (int i = 0; i < aMSC_1.data_symbols; i++) aMSC_1.symbol_count[i] = aMSC_1.distribution_forbidden[i]; aMSC_1.total_count = aMSC_1.pre_count;
	for (int i = 0; i < aMSC_2.data_symbols; i++) aMSC_2.symbol_count[i] = aMSC_2.distribution_forbidden[i]; aMSC_2.total_count = aMSC_2.pre_count;
	for (int i = 0; i < aMSC_3.data_symbols; i++) aMSC_3.symbol_count[i] = aMSC_3.distribution_forbidden[i]; aMSC_3.total_count = aMSC_3.pre_count;
	for (int i = 0; i < aMSC_4.data_symbols; i++) aMSC_4.symbol_count[i] = aMSC_4.distribution_forbidden[i]; aMSC_4.total_count = aMSC_4.pre_count;
	for (int i = 0; i < aMSC_5.data_symbols; i++) aMSC_5.symbol_count[i] = aMSC_5.distribution_forbidden[i]; aMSC_5.total_count = aMSC_5.pre_count;
	for (int i = 0; i < aMSC_6.data_symbols; i++) aMSC_6.symbol_count[i] = aMSC_6.distribution_forbidden[i]; aMSC_6.total_count = aMSC_6.pre_count;
	for (int i = 0; i < aMSC_7.data_symbols; i++) aMSC_7.symbol_count[i] = aMSC_7.distribution_forbidden[i]; aMSC_7.total_count = aMSC_7.pre_count;
	for (int i = 0; i < aMSC_8.data_symbols; i++) aMSC_8.symbol_count[i] = aMSC_8.distribution_forbidden[i]; aMSC_8.total_count = aMSC_8.pre_count;
	for (int i = 0; i < aMSC_00.data_symbols; i++) aMSC_00.symbol_count[i] = aMSC_00.distribution_forbidden[i]; aMSC_00.total_count = aMSC_00.pre_count;
	for (int i = 0; i < aMSC_01.data_symbols; i++) aMSC_01.symbol_count[i] = aMSC_01.distribution_forbidden[i]; aMSC_01.total_count = aMSC_01.pre_count;
	for (int i = 0; i < aMSC_02.data_symbols; i++) aMSC_02.symbol_count[i] = aMSC_02.distribution_forbidden[i]; aMSC_02.total_count = aMSC_02.pre_count;
	for (int i = 0; i < aMSC_03.data_symbols; i++) aMSC_03.symbol_count[i] = aMSC_03.distribution_forbidden[i]; aMSC_03.total_count = aMSC_03.pre_count;
	for (int i = 0; i < aMSC_04.data_symbols; i++) aMSC_04.symbol_count[i] = aMSC_04.distribution_forbidden[i]; aMSC_04.total_count = aMSC_04.pre_count;
	for (int i = 0; i < aMSC_05.data_symbols; i++) aMSC_05.symbol_count[i] = aMSC_05.distribution_forbidden[i]; aMSC_05.total_count = aMSC_05.pre_count;
	for (int i = 0; i < aMSC_06.data_symbols; i++) aMSC_06.symbol_count[i] = aMSC_06.distribution_forbidden[i]; aMSC_06.total_count = aMSC_06.pre_count;
	for (int i = 0; i < aMSC_07.data_symbols; i++) aMSC_07.symbol_count[i] = aMSC_07.distribution_forbidden[i]; aMSC_07.total_count = aMSC_07.pre_count;
	for (int i = 0; i < aMSC_08.data_symbols; i++) aMSC_08.symbol_count[i] = aMSC_08.distribution_forbidden[i]; aMSC_08.total_count = aMSC_08.pre_count;
	for (int i = 0; i < aMSC_09.data_symbols; i++) aMSC_09.symbol_count[i] = aMSC_09.distribution_forbidden[i]; aMSC_09.total_count = aMSC_09.pre_count;
	for (int i = 0; i < aMSC_010.data_symbols; i++) aMSC_010.symbol_count[i] = aMSC_010.distribution_forbidden[i]; aMSC_010.total_count = aMSC_010.pre_count;
	for (int i = 0; i < aMSC_011.data_symbols; i++) aMSC_011.symbol_count[i] = aMSC_011.distribution_forbidden[i]; aMSC_011.total_count = aMSC_011.pre_count;
	for (int i = 0; i < aMSC_012.data_symbols; i++) aMSC_012.symbol_count[i] = aMSC_012.distribution_forbidden[i]; aMSC_012.total_count = aMSC_012.pre_count;
	for (int i = 0; i < aMSC_013.data_symbols; i++) aMSC_013.symbol_count[i] = aMSC_013.distribution_forbidden[i]; aMSC_013.total_count = aMSC_013.pre_count;
	for (int i = 0; i < aMSC_014.data_symbols; i++) aMSC_014.symbol_count[i] = aMSC_014.distribution_forbidden[i]; aMSC_014.total_count = aMSC_014.pre_count;
	for (int i = 0; i < aMSC_015.data_symbols; i++) aMSC_015.symbol_count[i] = aMSC_015.distribution_forbidden[i]; aMSC_015.total_count = aMSC_015.pre_count;
	for (int i = 0; i < aMSC_016.data_symbols; i++) aMSC_016.symbol_count[i] = aMSC_016.distribution_forbidden[i]; aMSC_016.total_count = aMSC_016.pre_count;
	for (int i = 0; i < aMSC_017.data_symbols; i++) aMSC_017.symbol_count[i] = aMSC_017.distribution_forbidden[i]; aMSC_017.total_count = aMSC_017.pre_count;
	for (int i = 0; i < aMSC_018.data_symbols; i++) aMSC_018.symbol_count[i] = aMSC_018.distribution_forbidden[i]; aMSC_018.total_count = aMSC_018.pre_count;
	for (int i = 0; i < aMSC_019.data_symbols; i++) aMSC_019.symbol_count[i] = aMSC_019.distribution_forbidden[i]; aMSC_019.total_count = aMSC_019.pre_count;
	for (int i = 0; i < aMSC_020.data_symbols; i++) aMSC_020.symbol_count[i] = aMSC_020.distribution_forbidden[i]; aMSC_020.total_count = aMSC_020.pre_count;
	for (int i = 0; i < aMSC_021.data_symbols; i++) aMSC_021.symbol_count[i] = aMSC_021.distribution_forbidden[i]; aMSC_021.total_count = aMSC_021.pre_count;
	for (int i = 0; i < aMSC_022.data_symbols; i++) aMSC_022.symbol_count[i] = aMSC_022.distribution_forbidden[i]; aMSC_022.total_count = aMSC_022.pre_count;
	for (int i = 0; i < aMSC_023.data_symbols; i++) aMSC_023.symbol_count[i] = aMSC_023.distribution_forbidden[i]; aMSC_023.total_count = aMSC_023.pre_count;
	for (int i = 0; i < aMSC_024.data_symbols; i++) aMSC_024.symbol_count[i] = aMSC_024.distribution_forbidden[i]; aMSC_024.total_count = aMSC_024.pre_count;
	for (int i = 0; i < aMSC_025.data_symbols; i++) aMSC_025.symbol_count[i] = aMSC_025.distribution_forbidden[i]; aMSC_025.total_count = aMSC_025.pre_count;
	for (int i = 0; i < aMSC_026.data_symbols; i++) aMSC_026.symbol_count[i] = aMSC_026.distribution_forbidden[i]; aMSC_026.total_count = aMSC_026.pre_count;
	for (int i = 0; i < aMSC_10.data_symbols; i++) aMSC_10.symbol_count[i] = aMSC_10.distribution_forbidden[i]; aMSC_10.total_count = aMSC_10.pre_count;
	for (int i = 0; i < aMSC_11.data_symbols; i++) aMSC_11.symbol_count[i] = aMSC_11.distribution_forbidden[i]; aMSC_11.total_count = aMSC_11.pre_count;
	for (int i = 0; i < aMSC_12.data_symbols; i++) aMSC_12.symbol_count[i] = aMSC_12.distribution_forbidden[i]; aMSC_12.total_count = aMSC_12.pre_count;
	for (int i = 0; i < aMSC_13.data_symbols; i++) aMSC_13.symbol_count[i] = aMSC_13.distribution_forbidden[i]; aMSC_13.total_count = aMSC_13.pre_count;
	for (int i = 0; i < aMSC_14.data_symbols; i++) aMSC_14.symbol_count[i] = aMSC_14.distribution_forbidden[i]; aMSC_14.total_count = aMSC_14.pre_count;
	for (int i = 0; i < aMSC_15.data_symbols; i++) aMSC_15.symbol_count[i] = aMSC_15.distribution_forbidden[i]; aMSC_15.total_count = aMSC_15.pre_count;
	for (int i = 0; i < aMSC_16.data_symbols; i++) aMSC_16.symbol_count[i] = aMSC_16.distribution_forbidden[i]; aMSC_16.total_count = aMSC_16.pre_count;
	for (int i = 0; i < aMSC_17.data_symbols; i++) aMSC_17.symbol_count[i] = aMSC_17.distribution_forbidden[i]; aMSC_17.total_count = aMSC_17.pre_count;
	for (int i = 0; i < aMSC_18.data_symbols; i++) aMSC_18.symbol_count[i] = aMSC_18.distribution_forbidden[i]; aMSC_18.total_count = aMSC_18.pre_count;
	for (int i = 0; i < aMSC_19.data_symbols; i++) aMSC_19.symbol_count[i] = aMSC_19.distribution_forbidden[i]; aMSC_19.total_count = aMSC_19.pre_count;
	for (int i = 0; i < aMSC_110.data_symbols; i++) aMSC_110.symbol_count[i] = aMSC_110.distribution_forbidden[i]; aMSC_110.total_count = aMSC_110.pre_count;
	for (int i = 0; i < aMSC_111.data_symbols; i++) aMSC_111.symbol_count[i] = aMSC_111.distribution_forbidden[i]; aMSC_111.total_count = aMSC_111.pre_count;
	for (int i = 0; i < aMSC_112.data_symbols; i++) aMSC_112.symbol_count[i] = aMSC_112.distribution_forbidden[i]; aMSC_112.total_count = aMSC_112.pre_count;
	for (int i = 0; i < aMSC_113.data_symbols; i++) aMSC_113.symbol_count[i] = aMSC_113.distribution_forbidden[i]; aMSC_113.total_count = aMSC_113.pre_count;
	for (int i = 0; i < aMSC_114.data_symbols; i++) aMSC_114.symbol_count[i] = aMSC_114.distribution_forbidden[i]; aMSC_114.total_count = aMSC_114.pre_count;
	for (int i = 0; i < aMSC_115.data_symbols; i++) aMSC_115.symbol_count[i] = aMSC_115.distribution_forbidden[i]; aMSC_115.total_count = aMSC_115.pre_count;
	for (int i = 0; i < aMSC_116.data_symbols; i++) aMSC_116.symbol_count[i] = aMSC_116.distribution_forbidden[i]; aMSC_116.total_count = aMSC_116.pre_count;
	for (int i = 0; i < aMSC_117.data_symbols; i++) aMSC_117.symbol_count[i] = aMSC_117.distribution_forbidden[i]; aMSC_117.total_count = aMSC_117.pre_count;
	for (int i = 0; i < aMSC_118.data_symbols; i++) aMSC_118.symbol_count[i] = aMSC_118.distribution_forbidden[i]; aMSC_118.total_count = aMSC_118.pre_count;
	for (int i = 0; i < aMSC_119.data_symbols; i++) aMSC_119.symbol_count[i] = aMSC_119.distribution_forbidden[i]; aMSC_119.total_count = aMSC_119.pre_count;
	for (int i = 0; i < aMSC_120.data_symbols; i++) aMSC_120.symbol_count[i] = aMSC_120.distribution_forbidden[i]; aMSC_120.total_count = aMSC_120.pre_count;
	for (int i = 0; i < aMSC_121.data_symbols; i++) aMSC_121.symbol_count[i] = aMSC_121.distribution_forbidden[i]; aMSC_121.total_count = aMSC_121.pre_count;
	for (int i = 0; i < aMSC_122.data_symbols; i++) aMSC_122.symbol_count[i] = aMSC_122.distribution_forbidden[i]; aMSC_122.total_count = aMSC_122.pre_count;
	for (int i = 0; i < aMSC_123.data_symbols; i++) aMSC_123.symbol_count[i] = aMSC_123.distribution_forbidden[i]; aMSC_123.total_count = aMSC_123.pre_count;
	for (int i = 0; i < aMSC_124.data_symbols; i++) aMSC_124.symbol_count[i] = aMSC_124.distribution_forbidden[i]; aMSC_124.total_count = aMSC_124.pre_count;
	for (int i = 0; i < aMSC_125.data_symbols; i++) aMSC_125.symbol_count[i] = aMSC_125.distribution_forbidden[i]; aMSC_125.total_count = aMSC_125.pre_count;
	for (int i = 0; i < aMSC_126.data_symbols; i++) aMSC_126.symbol_count[i] = aMSC_126.distribution_forbidden[i]; aMSC_126.total_count = aMSC_126.pre_count;
	for (int i = 0; i < aMSC_20.data_symbols; i++) aMSC_20.symbol_count[i] = aMSC_20.distribution_forbidden[i]; aMSC_20.total_count = aMSC_20.pre_count;
	for (int i = 0; i < aMSC_21.data_symbols; i++) aMSC_21.symbol_count[i] = aMSC_21.distribution_forbidden[i]; aMSC_21.total_count = aMSC_21.pre_count;
	for (int i = 0; i < aMSC_22.data_symbols; i++) aMSC_22.symbol_count[i] = aMSC_22.distribution_forbidden[i]; aMSC_22.total_count = aMSC_22.pre_count;
	for (int i = 0; i < aMSC_23.data_symbols; i++) aMSC_23.symbol_count[i] = aMSC_23.distribution_forbidden[i]; aMSC_23.total_count = aMSC_23.pre_count;
	for (int i = 0; i < aMSC_24.data_symbols; i++) aMSC_24.symbol_count[i] = aMSC_24.distribution_forbidden[i]; aMSC_24.total_count = aMSC_24.pre_count;
	for (int i = 0; i < aMSC_25.data_symbols; i++) aMSC_25.symbol_count[i] = aMSC_25.distribution_forbidden[i]; aMSC_25.total_count = aMSC_25.pre_count;
	for (int i = 0; i < aMSC_26.data_symbols; i++) aMSC_26.symbol_count[i] = aMSC_26.distribution_forbidden[i]; aMSC_26.total_count = aMSC_26.pre_count;
	for (int i = 0; i < aMSC_27.data_symbols; i++) aMSC_27.symbol_count[i] = aMSC_27.distribution_forbidden[i]; aMSC_27.total_count = aMSC_27.pre_count;
	for (int i = 0; i < aMSC_28.data_symbols; i++) aMSC_28.symbol_count[i] = aMSC_28.distribution_forbidden[i]; aMSC_28.total_count = aMSC_28.pre_count;
	for (int i = 0; i < aMSC_29.data_symbols; i++) aMSC_29.symbol_count[i] = aMSC_29.distribution_forbidden[i]; aMSC_29.total_count = aMSC_29.pre_count;
	for (int i = 0; i < aMSC_210.data_symbols; i++) aMSC_210.symbol_count[i] = aMSC_210.distribution_forbidden[i]; aMSC_210.total_count = aMSC_210.pre_count;
	for (int i = 0; i < aMSC_211.data_symbols; i++) aMSC_211.symbol_count[i] = aMSC_211.distribution_forbidden[i]; aMSC_211.total_count = aMSC_211.pre_count;
	for (int i = 0; i < aMSC_212.data_symbols; i++) aMSC_212.symbol_count[i] = aMSC_212.distribution_forbidden[i]; aMSC_212.total_count = aMSC_212.pre_count;
	for (int i = 0; i < aMSC_213.data_symbols; i++) aMSC_213.symbol_count[i] = aMSC_213.distribution_forbidden[i]; aMSC_213.total_count = aMSC_213.pre_count;
	for (int i = 0; i < aMSC_214.data_symbols; i++) aMSC_214.symbol_count[i] = aMSC_214.distribution_forbidden[i]; aMSC_214.total_count = aMSC_214.pre_count;
	for (int i = 0; i < aMSC_215.data_symbols; i++) aMSC_215.symbol_count[i] = aMSC_215.distribution_forbidden[i]; aMSC_215.total_count = aMSC_215.pre_count;
	for (int i = 0; i < aMSC_216.data_symbols; i++) aMSC_216.symbol_count[i] = aMSC_216.distribution_forbidden[i]; aMSC_216.total_count = aMSC_216.pre_count;
	for (int i = 0; i < aMSC_217.data_symbols; i++) aMSC_217.symbol_count[i] = aMSC_217.distribution_forbidden[i]; aMSC_217.total_count = aMSC_217.pre_count;
	for (int i = 0; i < aMSC_218.data_symbols; i++) aMSC_218.symbol_count[i] = aMSC_218.distribution_forbidden[i]; aMSC_218.total_count = aMSC_218.pre_count;
	for (int i = 0; i < aMSC_219.data_symbols; i++) aMSC_219.symbol_count[i] = aMSC_219.distribution_forbidden[i]; aMSC_219.total_count = aMSC_219.pre_count;
	for (int i = 0; i < aMSC_220.data_symbols; i++) aMSC_220.symbol_count[i] = aMSC_220.distribution_forbidden[i]; aMSC_220.total_count = aMSC_220.pre_count;
	for (int i = 0; i < aMSC_221.data_symbols; i++) aMSC_221.symbol_count[i] = aMSC_221.distribution_forbidden[i]; aMSC_221.total_count = aMSC_221.pre_count;
	for (int i = 0; i < aMSC_222.data_symbols; i++) aMSC_222.symbol_count[i] = aMSC_222.distribution_forbidden[i]; aMSC_222.total_count = aMSC_222.pre_count;
	for (int i = 0; i < aMSC_223.data_symbols; i++) aMSC_223.symbol_count[i] = aMSC_223.distribution_forbidden[i]; aMSC_223.total_count = aMSC_223.pre_count;
	for (int i = 0; i < aMSC_224.data_symbols; i++) aMSC_224.symbol_count[i] = aMSC_224.distribution_forbidden[i]; aMSC_224.total_count = aMSC_224.pre_count;
	for (int i = 0; i < aMSC_225.data_symbols; i++) aMSC_225.symbol_count[i] = aMSC_225.distribution_forbidden[i]; aMSC_225.total_count = aMSC_225.pre_count;
	for (int i = 0; i < aMSC_226.data_symbols; i++) aMSC_226.symbol_count[i] = aMSC_226.distribution_forbidden[i]; aMSC_226.total_count = aMSC_226.pre_count;
	for (int i = 0; i < aMSC_30.data_symbols; i++) aMSC_30.symbol_count[i] = aMSC_30.distribution_forbidden[i]; aMSC_30.total_count = aMSC_30.pre_count;
	for (int i = 0; i < aMSC_31.data_symbols; i++) aMSC_31.symbol_count[i] = aMSC_31.distribution_forbidden[i]; aMSC_31.total_count = aMSC_31.pre_count;
	for (int i = 0; i < aMSC_32.data_symbols; i++) aMSC_32.symbol_count[i] = aMSC_32.distribution_forbidden[i]; aMSC_32.total_count = aMSC_32.pre_count;
	for (int i = 0; i < aMSC_33.data_symbols; i++) aMSC_33.symbol_count[i] = aMSC_33.distribution_forbidden[i]; aMSC_33.total_count = aMSC_33.pre_count;
	for (int i = 0; i < aMSC_34.data_symbols; i++) aMSC_34.symbol_count[i] = aMSC_34.distribution_forbidden[i]; aMSC_34.total_count = aMSC_34.pre_count;
	for (int i = 0; i < aMSC_35.data_symbols; i++) aMSC_35.symbol_count[i] = aMSC_35.distribution_forbidden[i]; aMSC_35.total_count = aMSC_35.pre_count;
	for (int i = 0; i < aMSC_36.data_symbols; i++) aMSC_36.symbol_count[i] = aMSC_36.distribution_forbidden[i]; aMSC_36.total_count = aMSC_36.pre_count;
	for (int i = 0; i < aMSC_37.data_symbols; i++) aMSC_37.symbol_count[i] = aMSC_37.distribution_forbidden[i]; aMSC_37.total_count = aMSC_37.pre_count;
	for (int i = 0; i < aMSC_38.data_symbols; i++) aMSC_38.symbol_count[i] = aMSC_38.distribution_forbidden[i]; aMSC_38.total_count = aMSC_38.pre_count;
	for (int i = 0; i < aMSC_39.data_symbols; i++) aMSC_39.symbol_count[i] = aMSC_39.distribution_forbidden[i]; aMSC_39.total_count = aMSC_39.pre_count;
	for (int i = 0; i < aMSC_310.data_symbols; i++) aMSC_310.symbol_count[i] = aMSC_310.distribution_forbidden[i]; aMSC_310.total_count = aMSC_310.pre_count;
	for (int i = 0; i < aMSC_311.data_symbols; i++) aMSC_311.symbol_count[i] = aMSC_311.distribution_forbidden[i]; aMSC_311.total_count = aMSC_311.pre_count;
	for (int i = 0; i < aMSC_312.data_symbols; i++) aMSC_312.symbol_count[i] = aMSC_312.distribution_forbidden[i]; aMSC_312.total_count = aMSC_312.pre_count;
	for (int i = 0; i < aMSC_313.data_symbols; i++) aMSC_313.symbol_count[i] = aMSC_313.distribution_forbidden[i]; aMSC_313.total_count = aMSC_313.pre_count;
	for (int i = 0; i < aMSC_314.data_symbols; i++) aMSC_314.symbol_count[i] = aMSC_314.distribution_forbidden[i]; aMSC_314.total_count = aMSC_314.pre_count;
	for (int i = 0; i < aMSC_315.data_symbols; i++) aMSC_315.symbol_count[i] = aMSC_315.distribution_forbidden[i]; aMSC_315.total_count = aMSC_315.pre_count;
	for (int i = 0; i < aMSC_316.data_symbols; i++) aMSC_316.symbol_count[i] = aMSC_316.distribution_forbidden[i]; aMSC_316.total_count = aMSC_316.pre_count;
	for (int i = 0; i < aMSC_317.data_symbols; i++) aMSC_317.symbol_count[i] = aMSC_317.distribution_forbidden[i]; aMSC_317.total_count = aMSC_317.pre_count;
	for (int i = 0; i < aMSC_318.data_symbols; i++) aMSC_318.symbol_count[i] = aMSC_318.distribution_forbidden[i]; aMSC_318.total_count = aMSC_318.pre_count;
	for (int i = 0; i < aMSC_319.data_symbols; i++) aMSC_319.symbol_count[i] = aMSC_319.distribution_forbidden[i]; aMSC_319.total_count = aMSC_319.pre_count;
	for (int i = 0; i < aMSC_320.data_symbols; i++) aMSC_320.symbol_count[i] = aMSC_320.distribution_forbidden[i]; aMSC_320.total_count = aMSC_320.pre_count;
	for (int i = 0; i < aMSC_321.data_symbols; i++) aMSC_321.symbol_count[i] = aMSC_321.distribution_forbidden[i]; aMSC_321.total_count = aMSC_321.pre_count;
	for (int i = 0; i < aMSC_322.data_symbols; i++) aMSC_322.symbol_count[i] = aMSC_322.distribution_forbidden[i]; aMSC_322.total_count = aMSC_322.pre_count;
	for (int i = 0; i < aMSC_323.data_symbols; i++) aMSC_323.symbol_count[i] = aMSC_323.distribution_forbidden[i]; aMSC_323.total_count = aMSC_323.pre_count;
	for (int i = 0; i < aMSC_324.data_symbols; i++) aMSC_324.symbol_count[i] = aMSC_324.distribution_forbidden[i]; aMSC_324.total_count = aMSC_324.pre_count;
	for (int i = 0; i < aMSC_325.data_symbols; i++) aMSC_325.symbol_count[i] = aMSC_325.distribution_forbidden[i]; aMSC_325.total_count = aMSC_325.pre_count;
	for (int i = 0; i < aMSC_326.data_symbols; i++) aMSC_326.symbol_count[i] = aMSC_326.distribution_forbidden[i]; aMSC_326.total_count = aMSC_326.pre_count;
	for (int i = 0; i < aMSC_40.data_symbols; i++) aMSC_40.symbol_count[i] = aMSC_40.distribution_forbidden[i]; aMSC_40.total_count = aMSC_40.pre_count;
	for (int i = 0; i < aMSC_41.data_symbols; i++) aMSC_41.symbol_count[i] = aMSC_41.distribution_forbidden[i]; aMSC_41.total_count = aMSC_41.pre_count;
	for (int i = 0; i < aMSC_42.data_symbols; i++) aMSC_42.symbol_count[i] = aMSC_42.distribution_forbidden[i]; aMSC_42.total_count = aMSC_42.pre_count;
	for (int i = 0; i < aMSC_43.data_symbols; i++) aMSC_43.symbol_count[i] = aMSC_43.distribution_forbidden[i]; aMSC_43.total_count = aMSC_43.pre_count;
	for (int i = 0; i < aMSC_44.data_symbols; i++) aMSC_44.symbol_count[i] = aMSC_44.distribution_forbidden[i]; aMSC_44.total_count = aMSC_44.pre_count;
	for (int i = 0; i < aMSC_45.data_symbols; i++) aMSC_45.symbol_count[i] = aMSC_45.distribution_forbidden[i]; aMSC_45.total_count = aMSC_45.pre_count;
	for (int i = 0; i < aMSC_46.data_symbols; i++) aMSC_46.symbol_count[i] = aMSC_46.distribution_forbidden[i]; aMSC_46.total_count = aMSC_46.pre_count;
	for (int i = 0; i < aMSC_47.data_symbols; i++) aMSC_47.symbol_count[i] = aMSC_47.distribution_forbidden[i]; aMSC_47.total_count = aMSC_47.pre_count;
	for (int i = 0; i < aMSC_48.data_symbols; i++) aMSC_48.symbol_count[i] = aMSC_48.distribution_forbidden[i]; aMSC_48.total_count = aMSC_48.pre_count;
	for (int i = 0; i < aMSC_49.data_symbols; i++) aMSC_49.symbol_count[i] = aMSC_49.distribution_forbidden[i]; aMSC_49.total_count = aMSC_49.pre_count;
	for (int i = 0; i < aMSC_410.data_symbols; i++) aMSC_410.symbol_count[i] = aMSC_410.distribution_forbidden[i]; aMSC_410.total_count = aMSC_410.pre_count;
	for (int i = 0; i < aMSC_411.data_symbols; i++) aMSC_411.symbol_count[i] = aMSC_411.distribution_forbidden[i]; aMSC_411.total_count = aMSC_411.pre_count;
	for (int i = 0; i < aMSC_412.data_symbols; i++) aMSC_412.symbol_count[i] = aMSC_412.distribution_forbidden[i]; aMSC_412.total_count = aMSC_412.pre_count;
	for (int i = 0; i < aMSC_413.data_symbols; i++) aMSC_413.symbol_count[i] = aMSC_413.distribution_forbidden[i]; aMSC_413.total_count = aMSC_413.pre_count;
	for (int i = 0; i < aMSC_414.data_symbols; i++) aMSC_414.symbol_count[i] = aMSC_414.distribution_forbidden[i]; aMSC_414.total_count = aMSC_414.pre_count;
	for (int i = 0; i < aMSC_415.data_symbols; i++) aMSC_415.symbol_count[i] = aMSC_415.distribution_forbidden[i]; aMSC_415.total_count = aMSC_415.pre_count;
	for (int i = 0; i < aMSC_416.data_symbols; i++) aMSC_416.symbol_count[i] = aMSC_416.distribution_forbidden[i]; aMSC_416.total_count = aMSC_416.pre_count;
	for (int i = 0; i < aMSC_417.data_symbols; i++) aMSC_417.symbol_count[i] = aMSC_417.distribution_forbidden[i]; aMSC_417.total_count = aMSC_417.pre_count;
	for (int i = 0; i < aMSC_418.data_symbols; i++) aMSC_418.symbol_count[i] = aMSC_418.distribution_forbidden[i]; aMSC_418.total_count = aMSC_418.pre_count;
	for (int i = 0; i < aMSC_419.data_symbols; i++) aMSC_419.symbol_count[i] = aMSC_419.distribution_forbidden[i]; aMSC_419.total_count = aMSC_419.pre_count;
	for (int i = 0; i < aMSC_420.data_symbols; i++) aMSC_420.symbol_count[i] = aMSC_420.distribution_forbidden[i]; aMSC_420.total_count = aMSC_420.pre_count;
	for (int i = 0; i < aMSC_421.data_symbols; i++) aMSC_421.symbol_count[i] = aMSC_421.distribution_forbidden[i]; aMSC_421.total_count = aMSC_421.pre_count;
	for (int i = 0; i < aMSC_422.data_symbols; i++) aMSC_422.symbol_count[i] = aMSC_422.distribution_forbidden[i]; aMSC_422.total_count = aMSC_422.pre_count;
	for (int i = 0; i < aMSC_423.data_symbols; i++) aMSC_423.symbol_count[i] = aMSC_423.distribution_forbidden[i]; aMSC_423.total_count = aMSC_423.pre_count;
	for (int i = 0; i < aMSC_424.data_symbols; i++) aMSC_424.symbol_count[i] = aMSC_424.distribution_forbidden[i]; aMSC_424.total_count = aMSC_424.pre_count;
	for (int i = 0; i < aMSC_425.data_symbols; i++) aMSC_425.symbol_count[i] = aMSC_425.distribution_forbidden[i]; aMSC_425.total_count = aMSC_425.pre_count;
	for (int i = 0; i < aMSC_426.data_symbols; i++) aMSC_426.symbol_count[i] = aMSC_426.distribution_forbidden[i]; aMSC_426.total_count = aMSC_426.pre_count;
	for (int i = 0; i < aMSC_50.data_symbols; i++) aMSC_50.symbol_count[i] = aMSC_50.distribution_forbidden[i]; aMSC_50.total_count = aMSC_50.pre_count;
	for (int i = 0; i < aMSC_51.data_symbols; i++) aMSC_51.symbol_count[i] = aMSC_51.distribution_forbidden[i]; aMSC_51.total_count = aMSC_51.pre_count;
	for (int i = 0; i < aMSC_52.data_symbols; i++) aMSC_52.symbol_count[i] = aMSC_52.distribution_forbidden[i]; aMSC_52.total_count = aMSC_52.pre_count;
	for (int i = 0; i < aMSC_53.data_symbols; i++) aMSC_53.symbol_count[i] = aMSC_53.distribution_forbidden[i]; aMSC_53.total_count = aMSC_53.pre_count;
	for (int i = 0; i < aMSC_54.data_symbols; i++) aMSC_54.symbol_count[i] = aMSC_54.distribution_forbidden[i]; aMSC_54.total_count = aMSC_54.pre_count;
	for (int i = 0; i < aMSC_55.data_symbols; i++) aMSC_55.symbol_count[i] = aMSC_55.distribution_forbidden[i]; aMSC_55.total_count = aMSC_55.pre_count;
	for (int i = 0; i < aMSC_56.data_symbols; i++) aMSC_56.symbol_count[i] = aMSC_56.distribution_forbidden[i]; aMSC_56.total_count = aMSC_56.pre_count;
	for (int i = 0; i < aMSC_57.data_symbols; i++) aMSC_57.symbol_count[i] = aMSC_57.distribution_forbidden[i]; aMSC_57.total_count = aMSC_57.pre_count;
	for (int i = 0; i < aMSC_58.data_symbols; i++) aMSC_58.symbol_count[i] = aMSC_58.distribution_forbidden[i]; aMSC_58.total_count = aMSC_58.pre_count;
	for (int i = 0; i < aMSC_59.data_symbols; i++) aMSC_59.symbol_count[i] = aMSC_59.distribution_forbidden[i]; aMSC_59.total_count = aMSC_59.pre_count;
	for (int i = 0; i < aMSC_510.data_symbols; i++) aMSC_510.symbol_count[i] = aMSC_510.distribution_forbidden[i]; aMSC_510.total_count = aMSC_510.pre_count;
	for (int i = 0; i < aMSC_511.data_symbols; i++) aMSC_511.symbol_count[i] = aMSC_511.distribution_forbidden[i]; aMSC_511.total_count = aMSC_511.pre_count;
	for (int i = 0; i < aMSC_512.data_symbols; i++) aMSC_512.symbol_count[i] = aMSC_512.distribution_forbidden[i]; aMSC_512.total_count = aMSC_512.pre_count;
	for (int i = 0; i < aMSC_513.data_symbols; i++) aMSC_513.symbol_count[i] = aMSC_513.distribution_forbidden[i]; aMSC_513.total_count = aMSC_513.pre_count;
	for (int i = 0; i < aMSC_514.data_symbols; i++) aMSC_514.symbol_count[i] = aMSC_514.distribution_forbidden[i]; aMSC_514.total_count = aMSC_514.pre_count;
	for (int i = 0; i < aMSC_515.data_symbols; i++) aMSC_515.symbol_count[i] = aMSC_515.distribution_forbidden[i]; aMSC_515.total_count = aMSC_515.pre_count;
	for (int i = 0; i < aMSC_516.data_symbols; i++) aMSC_516.symbol_count[i] = aMSC_516.distribution_forbidden[i]; aMSC_516.total_count = aMSC_516.pre_count;
	for (int i = 0; i < aMSC_517.data_symbols; i++) aMSC_517.symbol_count[i] = aMSC_517.distribution_forbidden[i]; aMSC_517.total_count = aMSC_517.pre_count;
	for (int i = 0; i < aMSC_518.data_symbols; i++) aMSC_518.symbol_count[i] = aMSC_518.distribution_forbidden[i]; aMSC_518.total_count = aMSC_518.pre_count;
	for (int i = 0; i < aMSC_519.data_symbols; i++) aMSC_519.symbol_count[i] = aMSC_519.distribution_forbidden[i]; aMSC_519.total_count = aMSC_519.pre_count;
	for (int i = 0; i < aMSC_520.data_symbols; i++) aMSC_520.symbol_count[i] = aMSC_520.distribution_forbidden[i]; aMSC_520.total_count = aMSC_520.pre_count;
	for (int i = 0; i < aMSC_521.data_symbols; i++) aMSC_521.symbol_count[i] = aMSC_521.distribution_forbidden[i]; aMSC_521.total_count = aMSC_521.pre_count;
	for (int i = 0; i < aMSC_522.data_symbols; i++) aMSC_522.symbol_count[i] = aMSC_522.distribution_forbidden[i]; aMSC_522.total_count = aMSC_522.pre_count;
	for (int i = 0; i < aMSC_523.data_symbols; i++) aMSC_523.symbol_count[i] = aMSC_523.distribution_forbidden[i]; aMSC_523.total_count = aMSC_523.pre_count;
	for (int i = 0; i < aMSC_524.data_symbols; i++) aMSC_524.symbol_count[i] = aMSC_524.distribution_forbidden[i]; aMSC_524.total_count = aMSC_524.pre_count;
	for (int i = 0; i < aMSC_525.data_symbols; i++) aMSC_525.symbol_count[i] = aMSC_525.distribution_forbidden[i]; aMSC_525.total_count = aMSC_525.pre_count;
	for (int i = 0; i < aMSC_526.data_symbols; i++) aMSC_526.symbol_count[i] = aMSC_526.distribution_forbidden[i]; aMSC_526.total_count = aMSC_526.pre_count;
	for (int i = 0; i < aMSC_60.data_symbols; i++) aMSC_60.symbol_count[i] = aMSC_60.distribution_forbidden[i]; aMSC_60.total_count = aMSC_60.pre_count;
	for (int i = 0; i < aMSC_61.data_symbols; i++) aMSC_61.symbol_count[i] = aMSC_61.distribution_forbidden[i]; aMSC_61.total_count = aMSC_61.pre_count;
	for (int i = 0; i < aMSC_62.data_symbols; i++) aMSC_62.symbol_count[i] = aMSC_62.distribution_forbidden[i]; aMSC_62.total_count = aMSC_62.pre_count;
	for (int i = 0; i < aMSC_63.data_symbols; i++) aMSC_63.symbol_count[i] = aMSC_63.distribution_forbidden[i]; aMSC_63.total_count = aMSC_63.pre_count;
	for (int i = 0; i < aMSC_64.data_symbols; i++) aMSC_64.symbol_count[i] = aMSC_64.distribution_forbidden[i]; aMSC_64.total_count = aMSC_64.pre_count;
	for (int i = 0; i < aMSC_65.data_symbols; i++) aMSC_65.symbol_count[i] = aMSC_65.distribution_forbidden[i]; aMSC_65.total_count = aMSC_65.pre_count;
	for (int i = 0; i < aMSC_66.data_symbols; i++) aMSC_66.symbol_count[i] = aMSC_66.distribution_forbidden[i]; aMSC_66.total_count = aMSC_66.pre_count;
	for (int i = 0; i < aMSC_67.data_symbols; i++) aMSC_67.symbol_count[i] = aMSC_67.distribution_forbidden[i]; aMSC_67.total_count = aMSC_67.pre_count;
	for (int i = 0; i < aMSC_68.data_symbols; i++) aMSC_68.symbol_count[i] = aMSC_68.distribution_forbidden[i]; aMSC_68.total_count = aMSC_68.pre_count;
	for (int i = 0; i < aMSC_69.data_symbols; i++) aMSC_69.symbol_count[i] = aMSC_69.distribution_forbidden[i]; aMSC_69.total_count = aMSC_69.pre_count;
	for (int i = 0; i < aMSC_610.data_symbols; i++) aMSC_610.symbol_count[i] = aMSC_610.distribution_forbidden[i]; aMSC_610.total_count = aMSC_610.pre_count;
	for (int i = 0; i < aMSC_611.data_symbols; i++) aMSC_611.symbol_count[i] = aMSC_611.distribution_forbidden[i]; aMSC_611.total_count = aMSC_611.pre_count;
	for (int i = 0; i < aMSC_612.data_symbols; i++) aMSC_612.symbol_count[i] = aMSC_612.distribution_forbidden[i]; aMSC_612.total_count = aMSC_612.pre_count;
	for (int i = 0; i < aMSC_613.data_symbols; i++) aMSC_613.symbol_count[i] = aMSC_613.distribution_forbidden[i]; aMSC_613.total_count = aMSC_613.pre_count;
	for (int i = 0; i < aMSC_614.data_symbols; i++) aMSC_614.symbol_count[i] = aMSC_614.distribution_forbidden[i]; aMSC_614.total_count = aMSC_614.pre_count;
	for (int i = 0; i < aMSC_615.data_symbols; i++) aMSC_615.symbol_count[i] = aMSC_615.distribution_forbidden[i]; aMSC_615.total_count = aMSC_615.pre_count;
	for (int i = 0; i < aMSC_616.data_symbols; i++) aMSC_616.symbol_count[i] = aMSC_616.distribution_forbidden[i]; aMSC_616.total_count = aMSC_616.pre_count;
	for (int i = 0; i < aMSC_617.data_symbols; i++) aMSC_617.symbol_count[i] = aMSC_617.distribution_forbidden[i]; aMSC_617.total_count = aMSC_617.pre_count;
	for (int i = 0; i < aMSC_618.data_symbols; i++) aMSC_618.symbol_count[i] = aMSC_618.distribution_forbidden[i]; aMSC_618.total_count = aMSC_618.pre_count;
	for (int i = 0; i < aMSC_619.data_symbols; i++) aMSC_619.symbol_count[i] = aMSC_619.distribution_forbidden[i]; aMSC_619.total_count = aMSC_619.pre_count;
	for (int i = 0; i < aMSC_620.data_symbols; i++) aMSC_620.symbol_count[i] = aMSC_620.distribution_forbidden[i]; aMSC_620.total_count = aMSC_620.pre_count;
	for (int i = 0; i < aMSC_621.data_symbols; i++) aMSC_621.symbol_count[i] = aMSC_621.distribution_forbidden[i]; aMSC_621.total_count = aMSC_621.pre_count;
	for (int i = 0; i < aMSC_622.data_symbols; i++) aMSC_622.symbol_count[i] = aMSC_622.distribution_forbidden[i]; aMSC_622.total_count = aMSC_622.pre_count;
	for (int i = 0; i < aMSC_623.data_symbols; i++) aMSC_623.symbol_count[i] = aMSC_623.distribution_forbidden[i]; aMSC_623.total_count = aMSC_623.pre_count;
	for (int i = 0; i < aMSC_624.data_symbols; i++) aMSC_624.symbol_count[i] = aMSC_624.distribution_forbidden[i]; aMSC_624.total_count = aMSC_624.pre_count;
	for (int i = 0; i < aMSC_625.data_symbols; i++) aMSC_625.symbol_count[i] = aMSC_625.distribution_forbidden[i]; aMSC_625.total_count = aMSC_625.pre_count;
	for (int i = 0; i < aMSC_626.data_symbols; i++) aMSC_626.symbol_count[i] = aMSC_626.distribution_forbidden[i]; aMSC_626.total_count = aMSC_626.pre_count;
	for (int i = 0; i < aMSC_70.data_symbols; i++) aMSC_70.symbol_count[i] = aMSC_70.distribution_forbidden[i]; aMSC_70.total_count = aMSC_70.pre_count;
	for (int i = 0; i < aMSC_71.data_symbols; i++) aMSC_71.symbol_count[i] = aMSC_71.distribution_forbidden[i]; aMSC_71.total_count = aMSC_71.pre_count;
	for (int i = 0; i < aMSC_72.data_symbols; i++) aMSC_72.symbol_count[i] = aMSC_72.distribution_forbidden[i]; aMSC_72.total_count = aMSC_72.pre_count;
	for (int i = 0; i < aMSC_73.data_symbols; i++) aMSC_73.symbol_count[i] = aMSC_73.distribution_forbidden[i]; aMSC_73.total_count = aMSC_73.pre_count;
	for (int i = 0; i < aMSC_74.data_symbols; i++) aMSC_74.symbol_count[i] = aMSC_74.distribution_forbidden[i]; aMSC_74.total_count = aMSC_74.pre_count;
	for (int i = 0; i < aMSC_75.data_symbols; i++) aMSC_75.symbol_count[i] = aMSC_75.distribution_forbidden[i]; aMSC_75.total_count = aMSC_75.pre_count;
	for (int i = 0; i < aMSC_76.data_symbols; i++) aMSC_76.symbol_count[i] = aMSC_76.distribution_forbidden[i]; aMSC_76.total_count = aMSC_76.pre_count;
	for (int i = 0; i < aMSC_77.data_symbols; i++) aMSC_77.symbol_count[i] = aMSC_77.distribution_forbidden[i]; aMSC_77.total_count = aMSC_77.pre_count;
	for (int i = 0; i < aMSC_78.data_symbols; i++) aMSC_78.symbol_count[i] = aMSC_78.distribution_forbidden[i]; aMSC_78.total_count = aMSC_78.pre_count;
	for (int i = 0; i < aMSC_79.data_symbols; i++) aMSC_79.symbol_count[i] = aMSC_79.distribution_forbidden[i]; aMSC_79.total_count = aMSC_79.pre_count;
	for (int i = 0; i < aMSC_710.data_symbols; i++) aMSC_710.symbol_count[i] = aMSC_710.distribution_forbidden[i]; aMSC_710.total_count = aMSC_710.pre_count;
	for (int i = 0; i < aMSC_711.data_symbols; i++) aMSC_711.symbol_count[i] = aMSC_711.distribution_forbidden[i]; aMSC_711.total_count = aMSC_711.pre_count;
	for (int i = 0; i < aMSC_712.data_symbols; i++) aMSC_712.symbol_count[i] = aMSC_712.distribution_forbidden[i]; aMSC_712.total_count = aMSC_712.pre_count;
	for (int i = 0; i < aMSC_713.data_symbols; i++) aMSC_713.symbol_count[i] = aMSC_713.distribution_forbidden[i]; aMSC_713.total_count = aMSC_713.pre_count;
	for (int i = 0; i < aMSC_714.data_symbols; i++) aMSC_714.symbol_count[i] = aMSC_714.distribution_forbidden[i]; aMSC_714.total_count = aMSC_714.pre_count;
	for (int i = 0; i < aMSC_715.data_symbols; i++) aMSC_715.symbol_count[i] = aMSC_715.distribution_forbidden[i]; aMSC_715.total_count = aMSC_715.pre_count;
	for (int i = 0; i < aMSC_716.data_symbols; i++) aMSC_716.symbol_count[i] = aMSC_716.distribution_forbidden[i]; aMSC_716.total_count = aMSC_716.pre_count;
	for (int i = 0; i < aMSC_717.data_symbols; i++) aMSC_717.symbol_count[i] = aMSC_717.distribution_forbidden[i]; aMSC_717.total_count = aMSC_717.pre_count;
	for (int i = 0; i < aMSC_718.data_symbols; i++) aMSC_718.symbol_count[i] = aMSC_718.distribution_forbidden[i]; aMSC_718.total_count = aMSC_718.pre_count;
	for (int i = 0; i < aMSC_719.data_symbols; i++) aMSC_719.symbol_count[i] = aMSC_719.distribution_forbidden[i]; aMSC_719.total_count = aMSC_719.pre_count;
	for (int i = 0; i < aMSC_720.data_symbols; i++) aMSC_720.symbol_count[i] = aMSC_720.distribution_forbidden[i]; aMSC_720.total_count = aMSC_720.pre_count;
	for (int i = 0; i < aMSC_721.data_symbols; i++) aMSC_721.symbol_count[i] = aMSC_721.distribution_forbidden[i]; aMSC_721.total_count = aMSC_721.pre_count;
	for (int i = 0; i < aMSC_722.data_symbols; i++) aMSC_722.symbol_count[i] = aMSC_722.distribution_forbidden[i]; aMSC_722.total_count = aMSC_722.pre_count;
	for (int i = 0; i < aMSC_723.data_symbols; i++) aMSC_723.symbol_count[i] = aMSC_723.distribution_forbidden[i]; aMSC_723.total_count = aMSC_723.pre_count;
	for (int i = 0; i < aMSC_724.data_symbols; i++) aMSC_724.symbol_count[i] = aMSC_724.distribution_forbidden[i]; aMSC_724.total_count = aMSC_724.pre_count;
	for (int i = 0; i < aMSC_725.data_symbols; i++) aMSC_725.symbol_count[i] = aMSC_725.distribution_forbidden[i]; aMSC_725.total_count = aMSC_725.pre_count;
	for (int i = 0; i < aMSC_726.data_symbols; i++) aMSC_726.symbol_count[i] = aMSC_726.distribution_forbidden[i]; aMSC_726.total_count = aMSC_726.pre_count;
	for (int i = 0; i < aMSC_80.data_symbols; i++) aMSC_80.symbol_count[i] = aMSC_80.distribution_forbidden[i]; aMSC_80.total_count = aMSC_80.pre_count;
	for (int i = 0; i < aMSC_81.data_symbols; i++) aMSC_81.symbol_count[i] = aMSC_81.distribution_forbidden[i]; aMSC_81.total_count = aMSC_81.pre_count;
	for (int i = 0; i < aMSC_82.data_symbols; i++) aMSC_82.symbol_count[i] = aMSC_82.distribution_forbidden[i]; aMSC_82.total_count = aMSC_82.pre_count;
	for (int i = 0; i < aMSC_83.data_symbols; i++) aMSC_83.symbol_count[i] = aMSC_83.distribution_forbidden[i]; aMSC_83.total_count = aMSC_83.pre_count;
	for (int i = 0; i < aMSC_84.data_symbols; i++) aMSC_84.symbol_count[i] = aMSC_84.distribution_forbidden[i]; aMSC_84.total_count = aMSC_84.pre_count;
	for (int i = 0; i < aMSC_85.data_symbols; i++) aMSC_85.symbol_count[i] = aMSC_85.distribution_forbidden[i]; aMSC_85.total_count = aMSC_85.pre_count;
	for (int i = 0; i < aMSC_86.data_symbols; i++) aMSC_86.symbol_count[i] = aMSC_86.distribution_forbidden[i]; aMSC_86.total_count = aMSC_86.pre_count;
	for (int i = 0; i < aMSC_87.data_symbols; i++) aMSC_87.symbol_count[i] = aMSC_87.distribution_forbidden[i]; aMSC_87.total_count = aMSC_87.pre_count;
	for (int i = 0; i < aMSC_88.data_symbols; i++) aMSC_88.symbol_count[i] = aMSC_88.distribution_forbidden[i]; aMSC_88.total_count = aMSC_88.pre_count;
	for (int i = 0; i < aMSC_89.data_symbols; i++) aMSC_89.symbol_count[i] = aMSC_89.distribution_forbidden[i]; aMSC_89.total_count = aMSC_89.pre_count;
	for (int i = 0; i < aMSC_810.data_symbols; i++) aMSC_810.symbol_count[i] = aMSC_810.distribution_forbidden[i]; aMSC_810.total_count = aMSC_810.pre_count;
	for (int i = 0; i < aMSC_811.data_symbols; i++) aMSC_811.symbol_count[i] = aMSC_811.distribution_forbidden[i]; aMSC_811.total_count = aMSC_811.pre_count;
	for (int i = 0; i < aMSC_812.data_symbols; i++) aMSC_812.symbol_count[i] = aMSC_812.distribution_forbidden[i]; aMSC_812.total_count = aMSC_812.pre_count;
	for (int i = 0; i < aMSC_813.data_symbols; i++) aMSC_813.symbol_count[i] = aMSC_813.distribution_forbidden[i]; aMSC_813.total_count = aMSC_813.pre_count;
	for (int i = 0; i < aMSC_814.data_symbols; i++) aMSC_814.symbol_count[i] = aMSC_814.distribution_forbidden[i]; aMSC_814.total_count = aMSC_814.pre_count;
	for (int i = 0; i < aMSC_815.data_symbols; i++) aMSC_815.symbol_count[i] = aMSC_815.distribution_forbidden[i]; aMSC_815.total_count = aMSC_815.pre_count;
	for (int i = 0; i < aMSC_816.data_symbols; i++) aMSC_816.symbol_count[i] = aMSC_816.distribution_forbidden[i]; aMSC_816.total_count = aMSC_816.pre_count;
	for (int i = 0; i < aMSC_817.data_symbols; i++) aMSC_817.symbol_count[i] = aMSC_817.distribution_forbidden[i]; aMSC_817.total_count = aMSC_817.pre_count;
	for (int i = 0; i < aMSC_818.data_symbols; i++) aMSC_818.symbol_count[i] = aMSC_818.distribution_forbidden[i]; aMSC_818.total_count = aMSC_818.pre_count;
	for (int i = 0; i < aMSC_819.data_symbols; i++) aMSC_819.symbol_count[i] = aMSC_819.distribution_forbidden[i]; aMSC_819.total_count = aMSC_819.pre_count;
	for (int i = 0; i < aMSC_820.data_symbols; i++) aMSC_820.symbol_count[i] = aMSC_820.distribution_forbidden[i]; aMSC_820.total_count = aMSC_820.pre_count;
	for (int i = 0; i < aMSC_821.data_symbols; i++) aMSC_821.symbol_count[i] = aMSC_821.distribution_forbidden[i]; aMSC_821.total_count = aMSC_821.pre_count;
	for (int i = 0; i < aMSC_822.data_symbols; i++) aMSC_822.symbol_count[i] = aMSC_822.distribution_forbidden[i]; aMSC_822.total_count = aMSC_822.pre_count;
	for (int i = 0; i < aMSC_823.data_symbols; i++) aMSC_823.symbol_count[i] = aMSC_823.distribution_forbidden[i]; aMSC_823.total_count = aMSC_823.pre_count;
	for (int i = 0; i < aMSC_824.data_symbols; i++) aMSC_824.symbol_count[i] = aMSC_824.distribution_forbidden[i]; aMSC_824.total_count = aMSC_824.pre_count;
	for (int i = 0; i < aMSC_825.data_symbols; i++) aMSC_825.symbol_count[i] = aMSC_825.distribution_forbidden[i]; aMSC_825.total_count = aMSC_825.pre_count;
	for (int i = 0; i < aMSC_826.data_symbols; i++) aMSC_826.symbol_count[i] = aMSC_826.distribution_forbidden[i]; aMSC_826.total_count = aMSC_826.pre_count;
}