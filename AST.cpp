#include "AST.h"

//Use only operators listed in unordered map Can also use parentheses, Comma separated expressions
AST::AST(const std::string& expression)
{
    tokenize(expression);//Tokenizes expression
    power = {    //Sets operators and their priorities
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
        {",", -2}
    };

    auto reach = tokens.cbegin();
    root = resolve(tokens.begin(), tokens.end(), reach, 0);//Constructs the tree from given expression
}

AST::AST(const std::string &expression, std::vector<double> &args)
{
    tokenize(expression);//Tokenizes expression
    power = {   //Sets operators and their priorities
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
        {",", -2}
    };

    auto reach = tokens.cbegin();
    root = resolve(tokens.begin(), tokens.end(), reach, 0);//Constructs the tree from given expression
    if (root->val != ",") {//check if expression is comma separated
        std::cout << "Error: No comma's used " << std::endl;
    }
    else {
        collectArgs(root, args);//Collects function call arguments and pushes them into args
    }

}

AST::operator double()
{
    double result = calculate(root);
    if (result == std::numeric_limits<double>::max()) {//if max value returned means something gone wrong
        std::cout << "Something went wrong" << std::endl;
    }
    return result;
}

double AST::calculate(Node* root)
{
    //Recursively calculates value of expression
    if (!root) {
        return 0.0;
    }

    if (isdigit(root -> val[0]) || isdigit(root->val[1])) {
        return std::stod(root -> val);
    }

    if (root -> val == "+") {
        return calculate(root -> left) + calculate(root -> right);
    } else if (root -> val == "*") {
        return calculate(root -> left) * calculate(root -> right);
    } else if (root -> val == "/") {
        int rightval = calculate(root->right);
        if (rightval != 0)
            return static_cast<double>(static_cast<int>(calculate(root->left)) / rightval);
        else {
            std::cout << "Integer division by zero" << std::endl;
            return std::numeric_limits<double>::max();
        }
        //use double version below with expressions using double operands(uncomment double version)

        /*double rightval = calculate(root->right);
        if (rightval != 0)
            return calculate(root->left) / rightval;
        else {
            std::cout << "Integer division by zero" << std::endl;
            return std::numeric_limits<double>::max();
        }*/
    } else if (root -> val == "%") {
        double rightval = calculate(root -> right);
        if (rightval != 0) {
            return static_cast<int>(calculate(root -> left)) % static_cast<int>(rightval);
        } else {
            std::cout << "Integer division by zero" << std::endl;
            return std::numeric_limits<double>::max();
        }
    } else if (root -> val == "-") {
        return calculate(root -> left) - calculate(root -> right);
    } else if (root -> val == "<<") {
        return static_cast<int>(calculate(root -> left)) << static_cast<int>(calculate(root -> right));
    } else if (root -> val == ">>") {
        return static_cast<int>(calculate(root -> left)) >> static_cast<int>(calculate(root -> right));
    } else if (root -> val == "&") {
        return static_cast<int>(calculate(root -> left)) & static_cast<int>(calculate(root -> right));
    } else if (root -> val == "^") {
        return static_cast<int>(calculate(root -> left)) ^ static_cast<int>(calculate(root -> right));
    } else if (root -> val == "|") {
        return static_cast<int>(calculate(root -> left)) | static_cast<int>(calculate(root -> right));
    } else if (root -> val == "&&") {
        return calculate(root -> left) && calculate(root -> right);
    } else if (root -> val == "||") {
        return calculate(root -> left) || calculate(root -> right);
    } else if (root -> val == "==") {
        return calculate(root -> left) == calculate(root -> right);
    } else if (root -> val == "!=") {
        return calculate(root -> left) != calculate(root -> right);
    } else if (root -> val == "<") {
        return calculate(root -> left) < calculate(root -> right);
    } else if (root -> val == "<=") {
        return calculate(root -> left) <= calculate(root -> right);
    } else if (root -> val == ">=") {
        return calculate(root -> left) >= calculate(root -> right);
    } else if (root -> val == ">") {
        return calculate(root -> left) > calculate(root -> right);
    } else if (root -> val == "?") {
        if (calculate(root -> left) != 0) {
            return root -> right && root -> right -> left ? calculate(root -> right -> left) : std::numeric_limits<double>::max();
        } else {
            return root -> right && root -> right -> right ? calculate(root -> right -> right) : std::numeric_limits<double>::max();
        }
    } else if (root -> val == ">") {
        return calculate(root -> left) > calculate(root -> right);
    }else if (root->val == ",") {
        double previous = calculate(root->left);//First calculate expression before comma
        return  calculate(root->right);//then calculate and return last expression i.e. after comma
    }
    else {
        std::cout << "Using unsupported operator" << std::endl;
    }
    return std::numeric_limits<double>::max();
}

void AST::levelOrderTraversalHelper(Node* root)
{
    if (!root) {
        return;
    }

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
                //std::cout << block << block;
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

            }

            if (i != 0) {
                if (current && current -> isOperator) {
                    //std::cout << " , " << calculate(current);
                }
            }

            q.push(current -> left);
            q.push(current -> right);
            q.pop();
        }
       // std::cout << std::endl << std::endl; // Move to the next line after processing a level
    }
}

int AST::getHeight(Node* root)
{
    if (!root) {
        return 0;
    }

    return std::max(getHeight(root -> left), getHeight(root -> right)) + 1;
}

void AST::collectArgs(Node *node, std::vector<double> &args)
{
    if (node->val != ",") {//First met operator which is not comma, is the first argument, calculate it and return
        args.push_back(calculate(node));
        return;
    }

    collectArgs(node->left, args);

    args.push_back(calculate(node->right));//push every argument's value
}

void AST::levelOrderTraversal()
{
    levelOrderTraversalHelper(root);
}

void AST::tokenize(const std::string& input)
{

    std::stringstream iss(input);
    std::string token;


    //Tokenizes and separates every parentheses, comma's and numbers
    while (iss >> token)
    {
        if (token.size() == 1) {
            tokens.push_back(token);
        }
        else {
            if (token[0] == '(') {
                bool found = false;
                if (token[token.size() - 1] == ',') {
                    token.pop_back();
                    found = true;
                }

                int i = 0;
                while (token[i] == '(') {
                    tokens.push_back("(");
                    ++i;
                }

                tokens.push_back(token.substr(i));

                if(found){
                    tokens.push_back(",");
                }
            }
            else {
                if (token[token.size() - 1] == ')') {
                    int i = token.size() - 1;
                    std::vector<std::string> tmp;
                    while (token[i] == ')') {
                        tmp.push_back(")");
                        token.pop_back();
                        --i;
                    }

                    tokens.push_back(token);

                    for (const std::string& str : tmp) {
                        tokens.push_back(str);
                    }

                }
                else if (token[token.size() - 1] == ',') {
                    token.pop_back();
                    if (token[token.size() - 1] == ')') {
                        int i = token.size() - 1;
                        std::vector<std::string> tmp;
                        while (token[i] == ')') {
                            tmp.push_back(")");
                            token.pop_back();
                            --i;
                        }

                        tokens.push_back(token);

                        for (const std::string& str : tmp) {
                            tokens.push_back(str);
                        }
                    }
                    else {
                        tokens.push_back(token);
                    }

                    tokens.push_back(",");
                }
                else {
                    tokens.push_back(token);
                }
            }
        }

    }
}

AST::Node* AST::rrotate(Node* node)
{
    if (node) {
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
    if (l && l -> left && l -> isOperator && l -> left -> isOperator && power[l -> val] > power[l -> left->val] && (l -> level >= l -> left -> level)) {
        Node* root = rrotate(l);

        if (l && l -> left && l -> isOperator && l -> left -> isOperator && power[l -> val] > power[l -> left->val] && (l -> level >= l -> left -> level)) {
            root -> right = rrotate(l);
        }

        return root;
    }

    return nullptr;
}

AST::Node* AST::resolve(std::vector<std::string>::const_iterator start, std::vector<std::string>::const_iterator end, std::vector<std::string>::const_iterator& reach, int level)
{
    Node* op = nullptr;
    Node* l = nullptr;
    Node* r = nullptr;
    Node* ternarRoot = nullptr;
    Node* LastTernar = nullptr;
    Node* lastOp = nullptr;

    if (start == end - 1) {
        return new Node(*start, 0, level);
    }

    //Basic expression case like: 5 * 7
    if (std::distance(start, end) == 3) {
        l = new Node(*start, 0, level);
        op = new Node(*(start + 1), 0, level);
        r = new Node(*(start + 2), 0, level);
        op->left = l;
        op->right = r;
        reach = start + 2;
        return op;
    }

    for (auto& it = start; it != end; ++it) {
        if (isdigit((*it)[0])  || isdigit((*it)[1])) { //if current token is digit
            if (!l) {
                l = new Node(*it, false, level);
            } else {
                r = new Node(*it, false, level);
                if (op) {
                    op -> right = r;
                }
            }
        } else {
            Node* newop = new Node(*it, true, level); //If current token is operator

            if (newop -> val == "(") {
                if (op && !op->left) {
                    op -> left = l;
                }

                if (op) {
                    op -> right = resolve(++it, end, reach, level + 1);
                } else {
                    l = resolve(++it, end, reach, level + 1);
                }

                if (reach > it) {
                    it = reach;
                }

                if (!op) {
                    op = l;
                } else {
                    l = op;
                    r = nullptr;
                }

                continue;
            } else if (newop -> val == ")") {
                reach = it;
                if (l && !op -> left) {
                    op -> left = l;
                }

                if (r && !op -> right) {
                    op -> right = r;
                }

                break;
            }

            if (ternarRoot && newop->val == "?") {
                if (lastOp -> val != "?" && lastOp -> val != ":" && getHeight(LastTernar) <= getHeight(lastOp)) {
                    lastOp -> left = LastTernar -> right;
                    Node* lr = LastCheck(lastOp);
                    if (lr){
                        LastTernar -> right = lr;
                    }else{
                        LastTernar -> right = lastOp;
                    }
                    r = nullptr;
                }

                Node* start = LastTernar;
                Node* newopsleft = start -> right;
                start -> right = newop;
                newop -> left = newopsleft;
                if (!op -> left){
                    op -> left = l;
                }

                r = nullptr;
                l = newop;
                op = newop;
                LastTernar = newop;
                continue;
            }


            if (ternarRoot && newop -> val == ":") {
                if (lastOp -> val != "?" && lastOp -> val != ":" && getHeight(LastTernar) <= getHeight(lastOp)) {
                    lastOp -> left = LastTernar -> right;
                    Node* lr = LastCheck(lastOp);
                    if (lr){
                        LastTernar -> right = lr;
                    }else{
                        LastTernar -> right = lastOp;
                    }
                    r = nullptr;
                }


                if (l && l -> left && l -> isOperator && l -> left -> isOperator && power[l -> val] > power[l -> left -> val] &&
                    (l -> level >= l -> left -> level) && l -> val != ":" ) {
                    l = LastCheck(l);
                    op = l;
                }


                Node* start = ternarRoot;
                Node* koracharcakan = nullptr;
                while (start && start -> right && start -> right -> right) {
                    if (start -> val == "?" && start -> right -> val != ":"){
                        koracharcakan = start;
                    }
                    start = start -> right;
                }

                if (start -> val == "?" && start -> right->val != ":"){
                    koracharcakan = start;
                }

                if (!koracharcakan){
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
                LastTernar = newop;
                continue;
            }

            if (l && r && !r -> isOperator && !l -> isOperator) {
                op -> left = l;
                newop -> left = op;
                r = nullptr;
                l = newop;
                op = newop;
            } else if (l && l -> isOperator) {
                if (op && op -> left -> isOperator && (power[op -> val] > power[op -> left -> val])
                    && (op -> level >= op -> left -> level) && op -> val != "?" && op -> val != ":") {
                    newop -> left = rrotate(l);
                    Node* lr = newop -> left -> right;
                    if (lr && lr -> left && lr -> isOperator && lr -> left -> isOperator && power[lr -> val] > power[lr -> left -> val] && (lr -> level >= lr -> left -> level)) {
                        newop -> left -> right = rrotate(lr);
                    }
                } else {
                    newop -> left = l;
                }

                l = newop;
                op = newop;
            } else {
                op = newop;
            }

            if (!ternarRoot && op->val == "?") {
                ternarRoot = op;
                LastTernar = op;
            }

            if(newop->val != "?" || newop->val != ":"){
                lastOp = newop;
            }
        }
    }

    if (ternarRoot) {
        if (lastOp->left && lastOp->left->val == ":") {
            lastOp->left = LastTernar->right;
            Node* lr = LastCheck(lastOp);
            if (lr){
                LastTernar->right = lr;
            }else{
                LastTernar->right = lastOp;
            }
            r = nullptr;
        }

        return ternarRoot;
    }

    Node* root = nullptr;
    if(op && op->left->isOperator && (power[op->val] > power[op->left->val]) && (op->level >= op->left->level)){
        root = LastCheck(op);
    }

    if (!root){
        root = op;
    }

    return  root;
}
