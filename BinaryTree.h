#ifndef LAB3_BINARYTREE_H
#define LAB3_BINARYTREE_H

#include <iostream>
#include <cmath>
#include "Functor.h"

using namespace std;

template<typename T>
class BinaryTree {
public:
    class Node{
    public:
        Node* left, *right;
        T value;
    public:
        Node(T value){
            this->left = this->right = nullptr;
            this->value = value;
        }
    };
    Node* root;

    BinaryTree(){
        this->root = nullptr;
    }

    //добавление значения в дерево
    bool Add(T value)
    {
        //ссылка на предыдущий узел и текущий
        Node* before = nullptr, *after = this->root;

        //пока следующий узел не пустой
        while (after != nullptr)
        {
            //готовим предыдущий узел как текущий для следующей итерации
            //так как на след итерации текущий уже будет предыдущим
            before = after;
            //если вставляемое значение меньше значения текущего узла
            //то идем в левую часть
            if (value < after->value)
                after = after->left;
            else if (value > after->value) //иначе идем в правую часть
                after = after->right;
            else
            {
                //если такое значение уже есть в дереве то ничего не делаем
                return false;
            }
        }

        //создаем новый узел
        Node *newNode = new Node(value);

        if (this->root == nullptr) //если дерево изначально пустое
            this->root = newNode; // то корнем дерева станет просто новая нода
        else //если дерево не пустое то
        {
            //находим в левую или правую часть вставить новый
            //узел в зависимости от вставляемого значения
            if (value < before->value)
                before->left = newNode;
            else
                before->right = newNode;
        }
        return true;
    }
    //нерекурсивный метод поиска для пользователя
    //на вход значение , на выходе узел
    Node* Find(T value)
    {
        return this->Search(value, this->root);
    }

    //получение высоты дерева
    int GetHeight()
    {
        return this->GetHeight(this->root);
    }

    BinaryTree<T>* where(const Functor<T>& f){
        BinaryTree<T>* newB = new BinaryTree<T>();
        where(newB, this->root, f);
        return newB;
    }

    BinaryTree<T>* map(const Functor<T>& f){
        BinaryTree<T>* novii = new BinaryTree<T>();
        map(novii, this->root, f);
        return novii;
    }

    BinaryTree<T>* fusion(const BinaryTree<T>& b){
        BinaryTree<T>* res = new BinaryTree<T>();
        res->AddTree(this->root);
        res->AddTree(b.root);
        return res;
    }

    void KLP(){
        KLP(this->root);
    }
    void KPL(){
        KPL(this->root);
    }
    void PKL(){
        PKL(this->root);
    }
    void LKP(){
        LKP(this->root);
    }
    void LPK(){
        LPK(this->root);
    }
    void PLK(){
        PLK(this->root);
    }

    BinaryTree<T>* SubTree(const T& value){
        BinaryTree<T>* res = new BinaryTree<T>;
        Node* tmp = this->Search(value, this->root);
        if (tmp == nullptr){
            return nullptr;
        }
        res->AddTree(tmp);
        return res;
    }

    bool SearchElement(const T& value){
       return Search(value, this->root) != nullptr;
    }

    string KLPinS(){
        string res = " ";
        KLPinS(this->root, res);
        return res;
    }
    string KPLinS(){
        string res = " ";
        KPLinS(this->root, res);
        return res;
    }
    string LKPinS(){
        string res = " ";
        LKPinS(this->root, res);
        return res;
    }
    string PKLinS(){
        string res = " ";
        PKLinS(this->root, res);
        return res;
    }
    string LPKinS(){
        string res = " ";
        LPKinS(this->root, res);
        return res;
    }
    string PLKinS(){
        string res = " ";
        PLKinS(this->root, res);
        return res;
    }

    bool contains(BinaryTree<T>& other) const {
        bool res;
        other.contain(other.root, res, *this);
        return res;
    }


private:
    //служебный рекурсивный метод поиска
    Node* Search(T value, Node* parent)
    {
        if (parent != nullptr)
        {
            if (value == parent->value) return parent;
            if (value < parent->value)
                return Search(value, parent->left);
            else
                return Search(value, parent->right);
        }
        return nullptr;
    }

    //вспомогательный рекурсивный метод удаления
    Node* Remove(Node* parent, int key)
    {
        if (parent == nullptr)
            return parent;

        //если удаляемое значение находится в левой
        //части то уходим в левую часть дерева
        if (key < parent->value)
            parent->left = Remove(parent->left, key);
        else if (key > parent->value) // иначе в правую часть
            parent->value = Remove(parent->right, key);
        else //если это найденное значение то
        {
            //если у просматриваемого узла слева нет
            //узла то возвращается правый узел
            if (parent->left == nullptr)
                return parent->right;
            else if (parent->right == nullptr) //иначе левый
                return parent->left;

            //если у просматриваемого узла есть оба узла
            //то записывается в значение наименьшее
            parent->value = MinValue(parent->right);

            parent->right = Remove(parent->right, parent->value);
        }
        return parent;
    }
    //служебный метод поиска минимального значения
    int MinValue(Node* node)
    {
        int minv = node->value;
        while (node->left != nullptr)
        {
            minv = node->left->value;
            node = node->left;
        }
        return minv;
    }
    //служебный рекурсивный метод получения высоты
    int GetHeight(Node* parent)
    {
        return parent == nullptr ? 0 : max(GetHeight(parent->left), GetHeight(parent->right)) + 1;
    }

    void where(BinaryTree<T>* res, Node* parent, const Functor<T>& f){
        if(parent!= nullptr){
            where(res, parent->right, f);
            where(res, parent->left, f);
            if(f(parent->value))
                res->Add(parent->value);
        }
    }

    void map(BinaryTree<T>* res, Node* parent, const Functor<T>& f){
        if( parent != nullptr){
            map(res, parent->left, f);
            map(res, parent->right, f);
            res->Add(f(parent->value, parent->value));
        }
    }

    void AddTree(Node* parent){
        if (parent != nullptr)
        {
            this->AddTree(parent->left);
            this->AddTree(parent->right);
            this->Add(parent->value);
        }
    }

    //вывод дерева в виде:
    //корень
    //левое поддерево
    //правое поддерево
    void KLP(Node* parent)
    {
        if (parent != nullptr)
        {
            std::cout << parent->value << " ";
            KLP(parent->left);
            KLP(parent->right);
        }
    }

    //вывод дерева в виде:
    //левое поддерево
    //корень
    //правое поддерево
    void LKP(Node* parent)
    {
        if (parent != nullptr)
        {
            LKP(parent->left);
            std::cout << parent->value << " ";
            LKP(parent->right);
        }
    }

    //вывод дерева в виде:
    //левое поддерево
    //правое поддерево
    //корень
    void LPK(Node* parent)
    {
        if (parent != nullptr)
        {
            LPK(parent->left);
            LPK(parent->right);
            std::cout << parent->value << " ";
        }
    }

    void KPL(Node* parent){
        if (parent != nullptr){
            std::cout << parent->value << " ";
            KPL(parent->right);
            KPL(parent->left);
        }
    }

    void PKL(Node* parent){
        if (parent != nullptr){
            PKL(parent->right);
            std::cout << parent->value << " ";
            PKL(parent->left);
        }
    }

    void PLK(Node* parent){
        if(parent!= nullptr){
            PLK(parent->right);
            PLK(parent->left);
            std::cout << parent->value << " ";
        }
    }

    void KLPinS(Node* parent, string& res){
        if(parent != nullptr){
            res += to_string(parent->value) + " ";
            KLPinS(parent->left, res);
            KLPinS(parent->right, res);
        }
    }

    void KPLinS(Node* parent, string& res){
        if(parent != nullptr){
            res += to_string(parent->value) + " ";
            KPLinS(parent->right, res);
            KPLinS(parent->left, res);
        }
    }

    void LKPinS(Node* parent, string& res){
        if(parent != nullptr){
            LKPinS(parent->left, res);
            res += to_string(parent->value) + " ";
            LKPinS(parent->right, res);
        }
    }
    void PKLinS(Node* parent, string& res){
        if(parent != nullptr){
            PKLinS(parent->right, res);
            res += to_string(parent->value) + " ";
            PKLinS(parent->left, res);
        }
    }

    void LPKinS(Node* parent, string& res){
        if(parent != nullptr){
            LPKinS(parent->left, res);
            LPKinS(parent->right, res);
            res += to_string(parent->value) + " ";
        }
    }

    void PLKinS(Node* parent, string& res){
        if(parent != nullptr){
            PLKinS(parent->right, res);
            PLKinS(parent->left, res);
            res += to_string(parent->value) + " ";
        }
    }

    void contain(Node* current, bool& res, const BinaryTree<T>& other) {
        if(current != nullptr){
            this->contain(current->left, res, other);
            this->contain(current->right, res, other);
            if(!this->SearchElement(current->value))
                res = false;
            else res = true;
        }
    }


};


#endif
