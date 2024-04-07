#include "AST.h"


int main()
{
    //std::string s = "1 + 2 * 3 - 4 / 5 % 6 << 2 >> 1 & 3 ^ 2 | 4 * 5 + 6 - 7 / 8 % 9 << 3 >> 2 & 10 ^ 5 | 11 * 12 + 13 - 14 / 15 % 16 << 4 >> 3 & 17 ^ 6 | 18 * 19 + 20 - 21 / 22 % 23 << 5 >> 4 & 24 ^ 7 | 25 * 26 + 27 - 28 / 29 % 30 << 6 >> 5 & 31 ^ 8 | 32";// ";//
    //int x =          1 + 2 * 3 - 4 / 5 % 6 << 2 >> 1 & 3 ^ 2 | 4 * 5 + 6 - 7 / 8 % 9 << 3 >> 2 & 10 ^ 5 | 11 * 12 + 13 - 14 / 15 % 16 << 4 >> 3 & 17 ^ 6 | 18 * 19 + 20 - 21 / 22 % 23 << 5 >> 4 & 24 ^ 7 | 25 * 26 + 27 - 28 / 29 % 30 << 6 >> 5 & 31 ^ 8 | 32;// ; //

    //std::string s = "30 + 28 * 27 / 26 % 25 << 4 >> 3 & 24 ^ 23 | 22 * 21 + 20 - 19 / 18 % 17 << 5 >> 4 & 16 ^ 15 | 14 * 13 + 12 - 11 / 10 % 9 << 6 >> 5 & 8 ^ 7 | 6";
    //int x =          30 + 28 * 27 / 26 % 25 << 4 >> 3 & 24 ^ 23 | 22 * 21 + 20 - 19 / 18 % 17 << 5 >> 4 & 16 ^ 15 | 14 * 13 + 12 - 11 / 10 % 9 << 6 >> 5 & 8 ^ 7 | 6;

    //std::string s = "1 + 2 * 3 - 4 / 5 % 6 << 2 >> 1 & 3 ^ 2 | 4 * 5 + 6 - 7 / 8 % 9 << 3 >> 2 & 10 ^ 5 | 11 * 12 + 13 - 14 / 15 % 16 << 4 >> 3 & 17 ^ 6 | 18 * 19 + 20 - 21 / 22 % 23 << 5 >> 4 & 24 ^ 7 | 25 * 26 + 27 - 28 / 29 % 30 << 6 >> 5 & 31 ^ 8 | 32 + 33 * 34 - 35 / 36 % 37 << 2 >> 1 & 38 ^ 39 | 40 * 41 + 42 - 43 / 44 % 45 << 3 >> 2 & 46 ^ 47 | 48 * 49 + 50 - 51 / 52 % 53 << 4 >> 3 & 54 ^ 55 | 56 * 57 + 58 - 59 / 60 % 61 << 5 >> 4 & 62 ^ 63 | 64 * 65 + 66 - 67 / 68 % 69 << 6 >> 5 & 70 ^ 71 | 72 * 73 + 74 - 75 / 76 % 77 << 6 >> 5 & 78 ^ 79 | 80 * 81 + 82 - 83 / 84 % 85 << 6 >> 5 & 86 ^ 87 | 88 * 89 + 90 - 91 / 92 % 93 << 6 >> 5 & 94 ^ 95 | 96 * 97 + 98 - 99 / 100 % 101 << 6 >> 5 & 102 ^ 103 | 104";
    //int x =          1 + 2 * 3 - 4 / 5 % 6 << 2 >> 1 & 3 ^ 2 | 4 * 5 + 6 - 7 / 8 % 9 << 3 >> 2 & 10 ^ 5 | 11 * 12 + 13 - 14 / 15 % 16 << 4 >> 3 & 17 ^ 6 | 18 * 19 + 20 - 21 / 22 % 23 << 5 >> 4 & 24 ^ 7 | 25 * 26 + 27 - 28 / 29 % 30 << 6 >> 5 & 31 ^ 8 | 32 + 33 * 34 - 35 / 36 % 37 << 2 >> 1 & 38 ^ 39 | 40 * 41 + 42 - 43 / 44 % 45 << 3 >> 2 & 46 ^ 47 | 48 * 49 + 50 - 51 / 52 % 53 << 4 >> 3 & 54 ^ 55 | 56 * 57 + 58 - 59 / 60 % 61 << 5 >> 4 & 62 ^ 63 | 64 * 65 + 66 - 67 / 68 % 69 << 6 >> 5 & 70 ^ 71 | 72 * 73 + 74 - 75 / 76 % 77 << 6 >> 5 & 78 ^ 79 | 80 * 81 + 82 - 83 / 84 % 85 << 6 >> 5 & 86 ^ 87 | 88 * 89 + 90 - 91 / 92 % 93 << 6 >> 5 & 94 ^ 95 | 96 * 97 + 98 - 99 / 100 % 101 << 6 >> 5 & 102 ^ 103 | 104;

    //std::string s = "5.75 * 2.25 + 3.5 / 4.75 - 1.25 * 2.5 / 3.25 + 4.5 - 3.75 * 5.25 / 2.0 + 6.125 * 7.625 / 8.25 - 9.0 + 10.125 / 2.5 * 3.75 - 4.25 / 5.5 + 6.75 * 7.875 / 8.125 - 9.25 + 10.25 / 2.25 * 3.5 - 4.75 / 5.125 + 6.375 * 7.75 / 8.375 - 9.5 + 10.5 / 2.125 * 3.625 - 4.875 / 5.75 + 6.875 * 7.25 / 8.625 - 9.625 + 10.75 / 2.625 * 3.875 - 4.625 / 5.875 + 6.75 * 7.25 / 8.875 - 9.875 + 10.875 / 2.875 * 3.625";
    //double x =       5.75 * 2.25 + 3.5 / 4.75 - 1.25 * 2.5 / 3.25 + 4.5 - 3.75 * 5.25 / 2.0 + 6.125 * 7.625 / 8.25 - 9.0 + 10.125 / 2.5 * 3.75 - 4.25 / 5.5 + 6.75 * 7.875 / 8.125 - 9.25 + 10.25 / 2.25 * 3.5 - 4.75 / 5.125 + 6.375 * 7.75 / 8.375 - 9.5 + 10.5 / 2.125 * 3.625 - 4.875 / 5.75 + 6.875 * 7.25 / 8.625 - 9.625 + 10.75 / 2.625 * 3.875 - 4.625 / 5.875 + 6.75 * 7.25 / 8.875 - 9.875 + 10.875 / 2.875 * 3.625;
    

    //std::string s = "(((47 * (-48 / 49)) / (-50 % 51)) + ((-52 + (-53 * 54)) / (-55 * 56))) - 57";
    //int x =          (((47 * (-48 / 49)) / (-50 % 51)) + ((-52 + (-53 * 54)) / (-55 * 56))) - 57;
    
    //std::string s = "3 << 2 & 7 + 5 * 3 - 10 || 12 != 14 && 6 <= 8 && 7 == 7 || 18 & 2 || 20 >= 21 && 15 | 10 ^ 6 + 3 * 2 - 8 && 25 != 27 || 11 <= 13 || 17 == 17 || 30 & 5 || 32 >= 33";
    //int x =          3 << 2 & 7 + 5 * 3 - 10 || 12 != 14 && 6 <= 8 && 7 == 7 || 18 & 2 || 20 >= 21 && 15 | 10 ^ 6 + 3 * 2 - 8 && 25 != 27 || 11 <= 13 || 17 == 17 || 30 & 5 || 32 >= 33;

    //std::string s = "(((5.75 * 2.25) + (3.5 / 4.75)) - ((1.25 * 2.5) / 3.25)) + (((4.5 - (3.75 * 5.25)) / 2.0) + ((6.125 * 7.625) / 8.25)) - (((9.0 + (10.125 / 2.5) * 3.75) - (4.25 / 5.5)) + ((6.75 * 7.875) / (8.125 - 9.25))) + (((10.25 / 2.25) * (3.5 - (4.75 / 5.125))) + ((6.375 * 7.75) / (8.375 - 9.5))) - ((((10.5 / 2.125) * 3.625) - (4.875 / 5.75)) + ((6.875 * 7.25) / (8.625 - 9.625))) + (((10.75 / 2.625) * (3.875 - (4.625 / 5.875))) + ((6.75 * 7.25) / (8.875 - 9.875))) - ((10.875 / (2.875 * 3.625)))";
    //double x =          (((5.75 * 2.25) + (3.5 / 4.75)) - ((1.25 * 2.5) / 3.25)) + (((4.5 - (3.75 * 5.25)) / 2.0) + ((6.125 * 7.625) / 8.25)) - (((9.0 + (10.125 / 2.5) * 3.75) - (4.25 / 5.5)) + ((6.75 * 7.875) / (8.125 - 9.25))) + (((10.25 / 2.25) * (3.5 - (4.75 / 5.125))) + ((6.375 * 7.75) / (8.375 - 9.5))) - ((((10.5 / 2.125) * 3.625) - (4.875 / 5.75)) + ((6.875 * 7.25) / (8.625 - 9.625))) + (((10.75 / 2.625) * (3.875 - (4.625 / 5.875))) + ((6.75 * 7.25) / (8.875 - 9.875))) - ((10.875 / (2.875 * 3.625)));
    
    //std::string s = "((((10 * ((5 + ((3 * 2)) + ((8 / 2))) - ((4 % 2))) << 1)) & (((7 ^ 3)) | ((5 << 1)) + (((6 - 2)) * ((10 + 2))))) | ((((12 << 2)) % 10)) & ((9 ^ 4))) | ((11 << 1)) + ((15 / 3)) + (((13 + 2)) * ((14 - 3))) - ((((16 >> 2)) | ((17 & 7))) * ((18 ^ 5)) + (((19 % 6)) - ((20 << 1)))) + ((((21 + ((22 * 2)) + (((23 + 3)) * ((24 / 4)))) >> 2)) & (((25 ^ 8)) | ((26 << 2)) + (((27 - 5)) * ((28 + 3))))) ^ (((29 << 1)) % 30) | (((31 ^ 9)) + (((32 + 4)) * ((33 - 6)))) - ((((34 >> 3)) | ((35 & 10))) * ((36 ^ 6)) + (((37 % 7)) - ((38 << 2)))) & ((((39 + ((40 * 3)) + (((41 + 5)) * ((42 / 5)))) << 2)) | ((43 ^ 7)) & (((44 << 1)) + (((45 - 4)) * ((46 + 2)))));";
    //int x =          ((((10 * ((5 + ((3 * 2)) + ((8 / 2))) - ((4 % 2))) << 1)) & (((7 ^ 3)) | ((5 << 1)) + (((6 - 2)) * ((10 + 2))))) | ((((12 << 2)) % 10)) & ((9 ^ 4))) | ((11 << 1)) + ((15 / 3)) + (((13 + 2)) * ((14 - 3))) - ((((16 >> 2)) | ((17 & 7))) * ((18 ^ 5)) + (((19 % 6)) - ((20 << 1)))) + ((((21 + ((22 * 2)) + (((23 + 3)) * ((24 / 4)))) >> 2)) & (((25 ^ 8)) | ((26 << 2)) + (((27 - 5)) * ((28 + 3))))) ^ (((29 << 1)) % 30) | (((31 ^ 9)) + (((32 + 4)) * ((33 - 6)))) - ((((34 >> 3)) | ((35 & 10))) * ((36 ^ 6)) + (((37 % 7)) - ((38 << 2)))) & ((((39 + ((40 * 3)) + (((41 + 5)) * ((42 / 5)))) << 2)) | ((43 ^ 7)) & (((44 << 1)) + (((45 - 4)) * ((46 + 2)))));

    //std::string s = "((2 + 5), (3 + 4), ((5 * 6), (7 - 8)), (9 / (10 + 11, 12)))";
    //int x =          ((2 + 5), (3 + 4), ((5 * 6), (7 - 8)), (9 / (10 + 11, 12)));

    //std::string s = "((((((((((((((((1 + (2 * 3)), (4 / 2)), ((5 - 1), (6 * 2)))), (((7 + (8 / 2)), (9 * 2)), ((10 - 2), (11 * 3))))), ((((12 + (13 * 2)), (14 / 2)), ((15 - 1), (16 * 2)))), (((17 + (18 / 2)), (19 * 2)), ((20 - 2), (21 * 3)))), (((((22 + (23 * 2)), (24 / 2)), ((25 - 1), (26 * 2)))), (((27 + (28 / 2)), (29 * 2)), ((30 - 2), (31 * 3))))), ((((32 + (33 * 2)), (34 / 2)), ((35 - 1), (36 * 2)))), (((37 + (38 / 2)), (39 * 2)), ((40 - 2), (41 * 3)))), ((((42 + (43 * 2)), (44 / 2)), ((45 - 1), (46 * 2)))), (((47 + (48 / 2)), (49 * 2)), ((50 - 2), (51 * 3))))), ((((((52 + (53 * 2)), (54 / 2)), ((55 - 1), (56 * 2)))), (((57 + (58 / 2)), (59 * 2)), ((60 - 2), (61 * 3))))), ((((62 + (63 * 2)), (64 / 2)), ((65 - 1), (66 * 2)))), (((67 + (68 / 2)), (69 * 2)), ((70 - 2), (71 * 3)))), (((((72 + (73 * 2)), (74 / 2)), ((75 - 1), (76 * 2)))), (((77 + (78 / 2)), (79 * 2)), ((80 - 2), (81 * 3))))), ((((82 + (83 * 2)), (84 / 2)), ((85 - 1), (86 * 2)))), (((87 + (88 / 2)), (89 * 2)), ((90 - 2), (91 * 3)))), ((((92 + (93 * 2)), (94 / 2)), ((95 - 1), (96 * 2)))), (((97 + (98 / 2)), (99 * 2)), ((100 - 2), (101 * 3)))));";
    //int x =          ((((((((((((((((1 + (2 * 3)), (4 / 2)), ((5 - 1), (6 * 2)))), (((7 + (8 / 2)), (9 * 2)), ((10 - 2), (11 * 3))))), ((((12 + (13 * 2)), (14 / 2)), ((15 - 1), (16 * 2)))), (((17 + (18 / 2)), (19 * 2)), ((20 - 2), (21 * 3)))), (((((22 + (23 * 2)), (24 / 2)), ((25 - 1), (26 * 2)))), (((27 + (28 / 2)), (29 * 2)), ((30 - 2), (31 * 3))))), ((((32 + (33 * 2)), (34 / 2)), ((35 - 1), (36 * 2)))), (((37 + (38 / 2)), (39 * 2)), ((40 - 2), (41 * 3)))), ((((42 + (43 * 2)), (44 / 2)), ((45 - 1), (46 * 2)))), (((47 + (48 / 2)), (49 * 2)), ((50 - 2), (51 * 3))))), ((((((52 + (53 * 2)), (54 / 2)), ((55 - 1), (56 * 2)))), (((57 + (58 / 2)), (59 * 2)), ((60 - 2), (61 * 3))))), ((((62 + (63 * 2)), (64 / 2)), ((65 - 1), (66 * 2)))), (((67 + (68 / 2)), (69 * 2)), ((70 - 2), (71 * 3)))), (((((72 + (73 * 2)), (74 / 2)), ((75 - 1), (76 * 2)))), (((77 + (78 / 2)), (79 * 2)), ((80 - 2), (81 * 3))))), ((((82 + (83 * 2)), (84 / 2)), ((85 - 1), (86 * 2)))), (((87 + (88 / 2)), (89 * 2)), ((90 - 2), (91 * 3)))), ((((92 + (93 * 2)), (94 / 2)), ((95 - 1), (96 * 2)))), (((97 + (98 / 2)), (99 * 2)), ((100 - 2), (101 * 3)))));
   
    //std::string s = "(((2 + (3 * 4)), ((5 - 6), (7 / 8)), (9 % 10), ((11 * 12), (13 - (14 / 15)))))";
    //int x =          (((2 + (3 * 4)), ((5 - 6), (7 / 8)), (9 % 10), ((11 * 12), (13 - (14 / 15)))));
    
    //Ternar cases
    //std::string s = "0 ? 0 : 0 ? 5 : 0 ? 7 : 0 ? 9 : 0 ? 11 : 10 ? 13 : 12 ? 15 : 14 ? 17 : 16 ? 19 : 18 ? 21 : 20 ? 23 : 22";
    //int x =          0 ? 0 : 0 ? 5 : 0 ? 7 : 0 ? 9 : 0 ? 11 : 10 ? 13 : 12 ? 15 : 14 ? 17 : 16 ? 19 : 18 ? 21 : 20 ? 23 : 22;

    //std::string s = "1 ? 9 || 4 != 3 ? 8 : 6 << 1 : 7";
    //int x =          1 ? 9 || 4 != 3 ? 8 : 6 << 1 : 7;

    //std::string s = "1 ? 2 + 3 ? 8 : 6 << 1 : 7";
    //int x =          1 ? 2 + 3 ? 8 : 6 << 1 : 7;

    //std::string s = "0 ?  3 != 3 ? 10 + 2 : 6 << 1 : 8";
    //int x =          0 ?  3 != 3 ? 10 + 2 : 6 << 1 : 8;

    //std::string s = "1 ? 9 / 3 != 3 ? 4 : 6 << 1 : 8";
    //int x =          1 ? 9 / 3 != 3 ? 4 : 6 << 1 : 8;

    //std::string s = "1 ? 6 * 6 + 9 / 3 * 5 : 2 + 9 * 5";
    //int x =          1 ? 6 * 6 + 9 / 3 * 5 : 2 + 9 * 5;

    //std::string s = "0 ? 0 ? 4 : 19 : 0 ? 5 : 0 ? 3 : 2 ? 10 : 6 ? 15 : 8 ? 20 : 0 ? 25 : 0 ? 30 : 0 ? 35 : 40";
    //int x =          0 ? 0 ? 4 : 19 : 0 ? 5 : 0 ? 3 : 2 ? 10 : 6 ? 15 : 8 ? 20 : 0 ? 25 : 0 ? 30 : 0 ? 35 : 40;

    //std::string s = "0 ? 0 ? 4 : 19 : 0 ? 5 : 0 ? 3 : 0 ? 10 : 0 ? 15 : 0 ? 20 : 0 ? 25 : 0 ? 30 : 0 ? 35 : 40 ? 2 ? 0 ? 6 : 9 : 0 ? 5 ? 10 : 15 : 7 ? 8 ? 12 : 18 : 11 ? 13 : 14 ? 20 ? 25 : 30 : 35 : 10";
    //int x =          0 ? 0 ? 4 : 19 : 0 ? 5 : 0 ? 3 : 0 ? 10 : 0 ? 15 : 0 ? 20 : 0 ? 25 : 0 ? 30 : 0 ? 35 : 40 ? 2 ? 0 ? 6 : 9 : 0 ? 5 ? 10 : 15 : 7 ? 8 ? 12 : 18 : 11 ? 13 : 14 ? 20 ? 25 : 30 : 35 : 10;

    //std::string s = "1 ? 1 ? 0 ? 5 : 3 : 2 : 1";
    //int x =          1 ? 1 ? 0 ? 5 : 3 : 2 : 1;

    //std::string s = "0 ? 6 : 5 + 10 * 4";
    //int x =          0 ? 6 : 5 + 10 * 4;    
    
    //std::string s = "(4 > 4 ? ((7 > 6) ? 10 : 20) : ((8 > 9) ? 30 : 40)) ? 50 : 60";
    //double x =       (4 > 4 ? ((7 > 6) ? 10 : 20) : ((8 > 9) ? 30 : 40)) ? 50 : 60;

    //std::string s = "((31 > 32) ? ((33 > 34) ? 220 : (35 > 36) ? ((37 > 38) ? 230 : 240) : 250) : ((39 > 40) ? ((41 > 42) ? 260 : 270) : 280)) ? (2 * 5 | 3) : 300";
    //double x =       ((31 > 32) ? ((33 > 34) ? 220 : (35 > 36) ? ((37 > 38) ? 230 : 240) : 250) : ((39 > 40) ? ((41 > 42) ? 260 : 270) : 280)) ? (2 * 5 | 3) : 300;

    //std::string s = "55 == 56 ? 15 & 5 || 9 / 3 != 3 ? 10 + 2 * 4 : 6 << 1 : 8 + 5 - 2";
    //int x =          55 == 56 ? 15 & 5 || 9 / 3 != 3 ? 10 + 2 * 4 : 6 << 1 : 8 + 5 - 2;
    
    //std::string s = "55 == 55 ? 15 & 5 || 9 / 3 != 3 ? 10 + 2 * 4 : 6 << 1 : 8 + 5 - 2";
    //int x =          55 == 55 ? 15 & 5 || 9 / 3 != 3 ? 10 + 2 * 4 : 6 << 1 : 8 + 5 - 2;
    
    //std::string s = "55 == 56 ? 7 : 15 & 5 || 9 / 3 != 3 ? 10 + 2 * 4 : 55 == 55 ? 15 & 5 || 9 / 3 != 3 ? 10 + 2 * 4 : 6 << 1 : 8 + 5 - 2";
    //int x =          55 == 56 ? 7 : 15 & 5 || 9 / 3 != 3 ? 10 + 2 * 4 : 55 == 55 ? 15 & 5 || 9 / 3 != 3 ? 10 + 2 * 4 : 6 << 1 : 8 + 5 - 2;
    
    //std::string s = "(55 == 56 ? 7 : 15 & 5 || 9 / 3 != 3) ? 10 + ((((47 * (-48 / 49)) / (-50 % 51)) + ((-52 + (-53 * 54)) / (-55 * 56))) - 57) : 55 == 55 ? (15 & 5 || 9 / 3 != 3 ? 10 + 2 * 4 : 6 << 1) : 8 + 5 - 2";
    //int x =          (55 == 56 ? 7 : 15 & 5 || 9 / 3 != 3) ? 10 + ((((47 * (-48 / 49)) / (-50 % 51)) + ((-52 + (-53 * 54)) / (-55 * 56))) - 57) : 55 == 55 ? (15 & 5 || 9 / 3 != 3 ? 10 + 2 * 4 : 6 << 1) : 8 + 5 - 2;

    std::string s = "1 ? (3 ? (0 ? 12 : (0 ? 15 : 10)) : (6 ? 14 : 9)) : (5 ? (4 ? 11 : 13) : 16)";
    int x =          1 ? (3 ? (0 ? 12 : (0 ? 15 : 10)) : (6 ? 14 : 9)) : (5 ? (4 ? 11 : 13) : 16);

    //std::vector<double> args;

    AST tree(s);

    /*for (auto& elem : args) {
        std::cout << elem << " ";
    }*/


    std::cout << "Expected Result: " << x << std::endl;

    std::cout << s << std::endl;

    std::cout << "Actual Result: " << tree << std::endl;
    
    tree.levelOrderTraversal();


}