#include "AST.h"

//Use only operators listed in unordered map(see below), Don't use ternar with chaining operations yet, use ternar only with numbers
AST::AST(const std::string& expression) {
    tokenize(expression);
    power = {
        {"*", 10},
        {"/", 10},
        {"%", 10},
        {"+", 9},
        {"-", 9},
        {"<<", 8},
        {">>", 8},
        {"<", 7},
        {">", 7},
        {"<=", 7},
        {">=", 7},
        {"==", 6},
        {"!=", 6},
        {"&", 5},
        {"^", 4},
        {"|", 3},
        {"&&", 2},
        {"||", 1},
        {":", 0},
        {"?", -1},
    };

    root = resolve(tokens.begin(), tokens.end());
}

double AST::calculate(Node* root)
{
    //Recursively calculates value of expression
    if (!root) {
        return 0;
    }

    if (isdigit(root -> val[0])) {
        return std::stod(root -> val);
    }

    if (root -> val == "+") {
        return calculate(root -> left) + calculate(root -> right);
    }
    else if (root -> val == "*") {
        return calculate(root -> left) * calculate(root -> right);
    }
    else if (root -> val == "/") {
        double rightval = calculate(root -> right);
        if (rightval != 0){
            return calculate(root -> left) / rightval;
        }else {
            std::cout << "Integer division by zero" << std::endl;
            return std::numeric_limits<double>::max();
        }
    }
    else if (root -> val == "%") {
        double rightval = calculate(root -> right);
        if (rightval != 0){
            return static_cast<int>(calculate(root -> left)) % static_cast<int>(rightval);
        }else {
            std::cout << "Integer division by zero" << std::endl;
            return std::numeric_limits<double>::max();
        }
    }
    else if (root -> val == "-") {
        return calculate(root -> left) - calculate(root -> right);
    }
    else if (root -> val == "<<") {
        return static_cast<int>(calculate(root -> left)) << static_cast<int>(calculate(root -> right));
    }
    else if (root -> val == ">>") {
        return static_cast<int>(calculate(root -> left)) >> static_cast<int>(calculate(root -> right));
    }
    else if (root -> val == "&") {
        return static_cast<int>(calculate(root -> left)) & static_cast<int>(calculate(root -> right));
    }
    else if (root -> val == "^") {
        return static_cast<int>(calculate(root -> left)) ^ static_cast<int>(calculate(root -> right));
    }
    else if (root -> val == "|") {
        return static_cast<int>(calculate(root -> left)) | static_cast<int>(calculate(root -> right));
    }
    else if (root -> val == "&&") {
        return calculate(root -> left) && calculate(root -> right);
    }
    else if (root -> val == "||") {
        return calculate(root -> left) || calculate(root -> right);
    }
    else if (root -> val == "==") {
        return calculate(root -> left) == calculate(root -> right);
    }
    else if (root -> val == "!=") {
        return calculate(root -> left) != calculate(root -> right);
    }
    else if (root -> val == "<") {
        return calculate(root -> left) < calculate(root -> right);
    }
    else if (root -> val == "<=") {
        return calculate(root -> left) <= calculate(root -> right);
    }
    else if (root -> val == ">=") {
        return calculate(root -> left) >= calculate(root -> right);
    }
    else if (root -> val == ">") {
        return calculate(root -> left) > calculate(root -> right);
    }
    else if (root -> val == "?") {
        if (calculate(root -> left) != 0){
            return root -> right && root -> right -> left ? calculate(root -> right -> left) : std::numeric_limits<double>::max();
        }else{
            return root -> right && root -> right -> right ? calculate(root -> right -> right) : std::numeric_limits<double>::max();
        }
    }
    else if (root -> val == ">") {
        return calculate(root -> left) > calculate(root -> right);
    }
    else {
        std::cout << "Using unsupported operator" << std::endl;
    }

    return std::numeric_limits<double>::max();
}

void AST::levelOrderTraversalHelper(Node* root)
{
    if (!root)
        return;

    std::string block = "     ";

    std::queue<Node*> q;//Queue is used to print tree level by level
    q.push(root);

    while (!q.empty()) {
        int levelSize = q.size(); // Number of nodes at the current level
        int height = 0;
        // Process all nodes at the current level
        for (int i = 0; i < levelSize; ++i) {
            Node* current = q.front();
            if (!current) {
                std::cout << block << block;
                q.pop();
                continue;
            }

            if (i == 0) {
                height = getHeight(current);
                std::string space;
                while (height + 1) {
                    space += block;
                    --height;
                }

                std::cout << space << current -> val;
                //if (current && current -> isOperator)
                    //std::cout << " , " << calculate(current);

                std::cout << block;
            }

            if (i != 0) {
                std::cout << block << current -> val;

                if (current && current -> isOperator)
                    std::cout << " , " << calculate(current);

                std::cout << block;
            }

            q.push(current -> left);

            q.push(current -> right);

            q.pop();
        }

        std::cout << std::endl << std::endl; // Move to the next line after processing a level
    }
}

int AST::getHeight(Node* root)
{
    if (!root)
        return 0;

    return std::max(getHeight(root -> left), getHeight(root -> right)) + 1;
}

double AST::calculate()
{
    double result = calculate(root);
    if (result == std::numeric_limits<double>::max()) {
        std::cout << "Something went wrong" << std::endl;
    }
    return result;
}

void AST::levelOrderTraversal()
{
    levelOrderTraversalHelper(root);
}

void AST::tokenize(const std::string& input)
{
    std::stringstream iss(input);
    std::string token;

    while (iss >> token){
        tokens.push_back(token);//Pushes every token into vector of tokens
    }

}

AST::Node* AST::rrotate(Node* node)
{
    if (node){
        Node* y = node -> left;
        Node* l2 = y -> right;
        y -> right = nullptr;
        node -> left = l2;
        y -> right = node;
        return y;
    }
    return nullptr;
}

AST::Node* AST::LastCheck(Node* l)
{
    //Both if's check if current op has higher priority if its left, and if True rotates subtrees
    if (l && l->left && l->isOperator && l->left->isOperator && power[l->val] > power[l->left->val])
    {
        Node* root = rrotate(l);

        if (l && l->left && l->isOperator && l->left->isOperator && power[l->val] > power[l->left->val]) {
            root->right = rrotate(l);
        }
        return root;
    }
    else
        return nullptr;
}

AST::Node* AST::resolve(std::vector<std::string>::const_iterator start, std::vector<std::string>::const_iterator end)
{
    Node* op = nullptr;
    Node* l = nullptr;
    Node* r = nullptr;

    if (start == end - 1) {
        return new Node(*start, 0);
    }

    //Basic expression case like: 5 * 7
    if (std::distance(start, end) == 3) {
        l = new Node(*start, 0);
        op = new Node(*(start + 1), 0);
        r = new Node(*(start + 2), 0);
        op -> left = l;
        op -> right = r;
        return op;
    }

    Node* ternarRoot = nullptr;//If there is ternar operator in our expression, first ternar will become root

    for (auto& it = start; it != end; ++it){
        if (isdigit((*it)[0])){//if current token is digit
            if (!l){
                l = new Node(*it, false);
            }
            else{
                r = new Node(*it, false);
                if (op){
                    op -> right = r;
                }
            }
        }
        else
        {
            Node* newop = new Node(*it, true);//If current token is operator

            if (ternarRoot && newop -> val == "?") {//if we met ?
                Node* start = op;

                Node* newopsleft = start -> right;
                start -> right = newop;
                newop -> left = newopsleft;
                if (!op -> left)
                    op -> left = l;

                r = nullptr;
                l = newop;
                op = newop;
                continue;
            }

            if (ternarRoot && newop -> val == ":") {//if we met :

                Node* start = ternarRoot;
                Node* koracharcakan = nullptr;
                while (start && start -> right && start -> right -> right) {
                    if (start -> val == "?" && start -> right -> val != ":"){
                        koracharcakan = start;
                    }
                    start = start -> right;
                }

                if (start -> val == "?" && start -> right -> val != ":"){
                    koracharcakan = start;
                }

                Node* iffalse = koracharcakan -> right;
                koracharcakan -> right = newop;
                newop -> left = iffalse;

                if (!op -> left){
                    op -> left = l;
                }

                r = nullptr;
                l = newop;
                op = newop;
                continue;
            }

            if (l && r && !r -> isOperator && !l -> isOperator){
                op -> left = l;
                newop -> left = op;
                r = nullptr;
                l = newop;
                op = newop;
            }
            else if (l && l -> isOperator){
                if (op && power[op -> val] > power[op -> left -> val]){
                    newop -> left = rrotate(l);
                    Node* lr = newop -> left -> right;
                    if (lr && lr -> left && lr -> isOperator && lr -> left -> isOperator
                        && power[lr -> val] > power[lr -> left -> val]) {
                        newop -> left -> right = rrotate(lr);
                    }
                }
                else{
                    newop -> left = l;
                }
                l = newop;
                op = newop;
            }
            else{
                op = newop;
            }

            if (!ternarRoot && op -> val == "?"){
                ternarRoot = op;
            }
        }
    }

    if (ternarRoot) {
        return ternarRoot;
    }

    Node* root = LastCheck(l);
    if (!root){
        root = op;
    }

    return root;
}
