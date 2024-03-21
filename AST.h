

//Use only operators listed in unordered map, except for ternar operator
class AST
{
public:
    AST(const std::string& expression);//Constructs Tree from given expression

    double calculate();//Wrapper around private calculate(Node*)

    void levelOrderTraversal();//Wrapper around private levelOrderTraversalHelper
private:
    struct Node//Node is either number node, or operator node
    {
        Node* left;
        Node* right;
        std::string val;
        bool isOperator;//Is Node containing operator value
        Node(std::string value, bool isOp) : left(nullptr), right(nullptr), val(value), isOperator(isOp) {}
        Node(std::string value, bool isOp, Node* l, Node* r) : left(l), right(r), val(value), isOperator(isOp) {}
    };

    void tokenize(const std::string& input);//Tokenizes string, dividing it into seprate tokens

    Node* rrotate(Node* node);//Right rotatation

    Node* LastCheck(Node* l);//Checks if there is need for rotations

    Node* resolve(std::vector<std::string> ::const_iterator start, std::vector<std::string> ::const_iterator end);//Here main
    //resolving logic is written

    double calculate(Node* root);//Returns value of expression

    void levelOrderTraversalHelper(Node* root);//Prints the tree

    int getHeight(Node* root);//Returns height of given node
private:
    std::vector<std::string> tokens;//Contains tokens
    Node* root;//Root operator of expression
    std::unordered_map<std::string, int> power;//Contains all operators with their priorities
};


//Test cases
// //Use only operators listed in unordered map, except for ternar operator

//int main()
//{
//    //std::string s = "1 + 2 * 3 - 4 / 5 % 6 << 2 >> 1 & 3 ^ 2 | 4 * 5 + 6 - 7 / 8 % 9 << 3 >> 2 & 10 ^ 5 | 11 * 12 + 13 - 14 / 15 % 16 << 4 >> 3 & 17 ^ 6 | 18 * 19 + 20 - 21 / 22 % 23 << 5 >> 4 & 24 ^ 7 | 25 * 26 + 27 - 28 / 29 % 30 << 6 >> 5 & 31 ^ 8 | 32";// ";//
//    //int x =          1 + 2 * 3 - 4 / 5 % 6 << 2 >> 1 & 3 ^ 2 | 4 * 5 + 6 - 7 / 8 % 9 << 3 >> 2 & 10 ^ 5 | 11 * 12 + 13 - 14 / 15 % 16 << 4 >> 3 & 17 ^ 6 | 18 * 19 + 20 - 21 / 22 % 23 << 5 >> 4 & 24 ^ 7 | 25 * 26 + 27 - 28 / 29 % 30 << 6 >> 5 & 31 ^ 8 | 32;// ; //
//
//    //std::string s = "30 + 28 * 27 / 26 % 25 << 4 >> 3 & 24 ^ 23 | 22 * 21 + 20 - 19 / 18 % 17 << 5 >> 4 & 16 ^ 15 | 14 * 13 + 12 - 11 / 10 % 9 << 6 >> 5 & 8 ^ 7 | 6";
//    //int x =          30 + 28 * 27 / 26 % 25 << 4 >> 3 & 24 ^ 23 | 22 * 21 + 20 - 19 / 18 % 17 << 5 >> 4 & 16 ^ 15 | 14 * 13 + 12 - 11 / 10 % 9 << 6 >> 5 & 8 ^ 7 | 6;
//
//    //std::string s = "1 + 2 * 3 - 4 / 5 % 6 << 2 >> 1 & 3 ^ 2 | 4 * 5 + 6 - 7 / 8 % 9 << 3 >> 2 & 10 ^ 5 | 11 * 12 + 13 - 14 / 15 % 16 << 4 >> 3 & 17 ^ 6 | 18 * 19 + 20 - 21 / 22 % 23 << 5 >> 4 & 24 ^ 7 | 25 * 26 + 27 - 28 / 29 % 30 << 6 >> 5 & 31 ^ 8 | 32 + 33 * 34 - 35 / 36 % 37 << 2 >> 1 & 38 ^ 39 | 40 * 41 + 42 - 43 / 44 % 45 << 3 >> 2 & 46 ^ 47 | 48 * 49 + 50 - 51 / 52 % 53 << 4 >> 3 & 54 ^ 55 | 56 * 57 + 58 - 59 / 60 % 61 << 5 >> 4 & 62 ^ 63 | 64 * 65 + 66 - 67 / 68 % 69 << 6 >> 5 & 70 ^ 71 | 72 * 73 + 74 - 75 / 76 % 77 << 6 >> 5 & 78 ^ 79 | 80 * 81 + 82 - 83 / 84 % 85 << 6 >> 5 & 86 ^ 87 | 88 * 89 + 90 - 91 / 92 % 93 << 6 >> 5 & 94 ^ 95 | 96 * 97 + 98 - 99 / 100 % 101 << 6 >> 5 & 102 ^ 103 | 104";
//    //int x =          1 + 2 * 3 - 4 / 5 % 6 << 2 >> 1 & 3 ^ 2 | 4 * 5 + 6 - 7 / 8 % 9 << 3 >> 2 & 10 ^ 5 | 11 * 12 + 13 - 14 / 15 % 16 << 4 >> 3 & 17 ^ 6 | 18 * 19 + 20 - 21 / 22 % 23 << 5 >> 4 & 24 ^ 7 | 25 * 26 + 27 - 28 / 29 % 30 << 6 >> 5 & 31 ^ 8 | 32 + 33 * 34 - 35 / 36 % 37 << 2 >> 1 & 38 ^ 39 | 40 * 41 + 42 - 43 / 44 % 45 << 3 >> 2 & 46 ^ 47 | 48 * 49 + 50 - 51 / 52 % 53 << 4 >> 3 & 54 ^ 55 | 56 * 57 + 58 - 59 / 60 % 61 << 5 >> 4 & 62 ^ 63 | 64 * 65 + 66 - 67 / 68 % 69 << 6 >> 5 & 70 ^ 71 | 72 * 73 + 74 - 75 / 76 % 77 << 6 >> 5 & 78 ^ 79 | 80 * 81 + 82 - 83 / 84 % 85 << 6 >> 5 & 86 ^ 87 | 88 * 89 + 90 - 91 / 92 % 93 << 6 >> 5 & 94 ^ 95 | 96 * 97 + 98 - 99 / 100 % 101 << 6 >> 5 & 102 ^ 103 | 104;
//
//    std::string s = "5.75 * 2.25 + 3.5 / 4.75 - 1.25 * 2.5 / 3.25 + 4.5 - 3.75 * 5.25 / 2.0 + 6.125 * 7.625 / 8.25 - 9.0 + 10.125 / 2.5 * 3.75 - 4.25 / 5.5 + 6.75 * 7.875 / 8.125 - 9.25 + 10.25 / 2.25 * 3.5 - 4.75 / 5.125 + 6.375 * 7.75 / 8.375 - 9.5 + 10.5 / 2.125 * 3.625 - 4.875 / 5.75 + 6.875 * 7.25 / 8.625 - 9.625 + 10.75 / 2.625 * 3.875 - 4.625 / 5.875 + 6.75 * 7.25 / 8.875 - 9.875 + 10.875 / 2.875 * 3.625";
//    double x = 5.75 * 2.25 + 3.5 / 4.75 - 1.25 * 2.5 / 3.25 + 4.5 - 3.75 * 5.25 / 2.0 + 6.125 * 7.625 / 8.25 - 9.0 + 10.125 / 2.5 * 3.75 - 4.25 / 5.5 + 6.75 * 7.875 / 8.125 - 9.25 + 10.25 / 2.25 * 3.5 - 4.75 / 5.125 + 6.375 * 7.75 / 8.375 - 9.5 + 10.5 / 2.125 * 3.625 - 4.875 / 5.75 + 6.875 * 7.25 / 8.625 - 9.625 + 10.75 / 2.625 * 3.875 - 4.625 / 5.875 + 6.75 * 7.25 / 8.875 - 9.875 + 10.875 / 2.875 * 3.625;
//
//    //std::string s = "0 ? 0 : 0 ? 5 : 0 ? 7 : 6 ? 9 : 8 ? 11 : 10 ? 13 : 12 ? 15 : 14 ? 17 : 16 ? 19 : 18 ? 21 : 20 ? 23 : 22";
//    //int x =          0 ? 0 : 0 ? 5 : 0 ? 7 : 6 ? 9 : 8 ? 11 : 10 ? 13 : 12 ? 15 : 14 ? 17 : 16 ? 19 : 18 ? 21 : 20 ? 23 : 22;
//
//    //std::string s = "55 == 56 ? 15 & 5 || 9 / 3 != 3 ? 10 + 2 * 4 : 6 << 1 : 8 + 5 - 2";
//    //int x =          55 == 56 ? 15 & 5 || 9 / 3 != 3 ? 10 + 2 * 4 : 6 << 1 : 8 + 5 - 2;
//
//    //std::string s = "55 == 55 ? 15 & 5 || 9 / 3 != 3 ? 10 + 2 * 4 : 6 << 1 : 8 + 5 - 2";
//    //int x =          55 == 55 ? 15 & 5 || 9 / 3 != 3 ? 10 + 2 * 4 : 6 << 1 : 8 + 5 - 2;
//
//    //std::string s = "0 ? 6 : 2";
//    //int x =          0 ? 6 : 2;
//
//    //std::string s = "0 ? 6 ? 5 : 3 : 2";
//    //int x =          0 ? 6 ? 5 : 3 : 2;
//
//    //std::string s = "0 ? 6 : 2 ? 4 : 10";
//    //int x =          0 ? 6 : 2 ? 4 : 10;
//
//    //std::string s = "10 <= 12 ? 5 + 3 * 2 == 6 ? 7 | 9 : 6 >> 1 : 15 + 2";
//    //int x =          10 <= 12 ? 5 + 3 * 2 == 6 ? 7 | 9 : 6 >> 1 : 15 + 2;
//
//    //std::string s = "3 << 2 & 7 + 5 * 3 - 10 || 12 != 14 && 6 <= 8 && 7 == 7 || 18 & 2 || 20 >= 21 && 15 | 10 ^ 6 + 3 * 2 - 8 && 25 != 27 || 11 <= 13 || 17 == 17 || 30 & 5 || 32 >= 33";
//    //int x =          3 << 2 & 7 + 5 * 3 - 10 || 12 != 14 && 6 <= 8 && 7 == 7 || 18 & 2 || 20 >= 21 && 15 | 10 ^ 6 + 3 * 2 - 8 && 25 != 27 || 11 <= 13 || 17 == 17 || 30 & 5 || 32 >= 33;
//
//
//    AST tree(s);
//
//    std::cout << "Expected Result: " << x << std::endl;
//
//    //std::cout << s << std::endl;
//
//    std::cout << "Actual Result: " << tree.calculate() << std::endl;
//
//    tree.levelOrderTraversal();
//
//    return 0;
//}

