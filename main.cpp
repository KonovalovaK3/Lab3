#include "BinaryTree.h"
#include "Complex.h"
#include "Student.h"
#include "Teacher.h"

void testInt();
void testFloat();
void testComplex();
void testStudent();
void testTeacher();

int main() {
    testInt();
    testFloat();
    testComplex();
    testStudent();
    testTeacher();
    return 0;
}

void testInt() {
    BinaryTree<int> a;
    a.Add(5);
    a.Add(-1);
    a.Add(2);
    a.Add(3);
    a.Add(-4);
    a.Add(6);
//добавила элементы
    a.LKP(); //вывод обхода лево-корень-право
    cout << a.LKPinS() << endl; //этот же обход, сохраненный в строку.
    a.LPK(); //лево-право-корень
    cout << a.LPKinS() << endl;
    a.KLP(); //корень-лево-право
    cout << a.KLPinS() << endl;
    a.KPL(); //корень-право-лево
    cout << a.KPLinS() << endl;
    a.PLK();//право-лево-корень
    cout << a.PLKinS() << endl;
    a.PKL(); //право-корень-лево
    cout << a.PKLinS() << endl;
//поиск выведенного элемента
    cout << "5" << a.Find(5)->value << endl;
//вывод высоты дерева
    cout << a.GetHeight() << endl;
//where где критерий - значение больше нуля
    IntFunctor f;
    a.where(f)->LKP();
//map где действие - возведение в квадрат
    a.map(f)->LKP();
//задала дерево, которое объединю со старым
    BinaryTree<int> b;
    b.Add(100);
    b.Add(203);
//объединение и вывод
    a.fusion(b)->LKP();
//вылеляю поддерево из первого дерева по значению элемента - корня будущего поддерева с проверкой на нуль-указатель
    if (a.SubTree(2) != nullptr) a.SubTree(2)->LKP();
//ищу существующий элемент
    if (a.SearchElement(3)) {
        cout << "yes" << endl;
    } else cout << "no" << endl;
//ищу несуществующий элемент
    if (a.SearchElement(202)) {
        cout << "yes" << endl;
    } else cout << "no" << endl;
//проверяю наличие поддерева в дереве
    BinaryTree<int>* c = a.fusion(b);
    if (c->contains(b)) {
        cout << "yes" << endl;
    } else cout << "no" << endl;
}

void testFloat(){
    const float k = 9.99;
    BinaryTree<float> a;
    a.Add(k);
    a.Add(-1.2121);
    a.Add(-203.00);
    a.Add(548.0/30.5);
    a.Add(-4.0594);
    a.Add(6.909909387);
//добавила элементы
    a.LKP(); //вывод обхода лево-корень-право
    cout << a.LKPinS() << endl; //этот же обход, сохраненный в строку.
    a.LPK(); //лево-право-корень
    cout << a.LPKinS() << endl;
    a.KLP(); //корень-лево-право
    cout << a.KLPinS() << endl;
    a.KPL(); //корень-право-лево
    cout << a.KPLinS() << endl;
    a.PLK();//право-лево-корень
    cout << a.PLKinS() << endl;
    a.PKL(); //право-корень-лево
    cout << a.PKLinS() << endl;
//поиск выведенного элемента
    cout << k << a.Find(k)->value << endl;
//вывод высоты дерева
    cout << a.GetHeight() << endl;
//where где критерий - модуль числа больше 101
    FloatFunctor f;
    a.where(f)->LKP();
//map где действие - среднее арифметическое с тройкой
    a.map(f)->LKP();
//задала дерево, которое объединю со старым
    BinaryTree<float> b;
    b.Add(100.01);
    b.Add(203.999443);
//объединение и вывод
    a.fusion(b)->LKP();
//вылеляю поддерево из первого дерева по значению элемента - корня будущего поддерева с проверкой на нуль-указатель
    if (a.SubTree(2) != nullptr) a.SubTree(k)->LKP();
//ищу существующий элемент
    if (a.SearchElement(k)) {
        cout << "yes" << endl;
    } else cout << "no" << endl;
//ищу несуществующий элемент
    if (a.SearchElement(1)) {
        cout << "yes" << endl;
    } else cout << "no" << endl;
//проверяю наличие поддерева в дереве
    BinaryTree<float>* c = a.fusion(b);
    if (c->contains(b)) {
        cout << "yes" << endl;
    } else cout << "no" << endl;
}
void testComplex(){
    BinaryTree<Complex> a;
    Complex a1(0, 0);
    Complex a2(50.43, 77.7777);
    Complex a3(-10.02235, 9.99294);
    Complex a4(9.0876, -209.49);
    Complex a5(-97832.937, -2987.9873676);
    Complex a6(1, 1);
    a.Add(a1);
    a.Add(a2);
    a.Add(a3);
    a.Add(a4);
    a.Add(a5);
    a.Add(a6);
//добавила элементы
    a.LKP(); //вывод обхода лево-корень-право (сравниваются модули комплексных чисел,
    // так как в математике не определено сравнение комплексных чисел)
    cout << a.LKPinS() << endl; //этот же обход, сохраненный в строку.
    a.LPK(); //лево-право-корень
    cout << a.LPKinS() << endl;
    a.KLP(); //корень-лево-право
    cout << a.KLPinS() << endl;
    a.KPL(); //корень-право-лево
    cout << a.KPLinS() << endl;
    a.PLK();//право-лево-корень
    cout << a.PLKinS() << endl;
    a.PKL(); //право-корень-лево
    cout << a.PKLinS() << endl;
//поиск выведенного элемента
    cout << a5 << a.Find(a5)->value << endl;
//вывод высоты дерева
    cout << a.GetHeight() << endl;
//where где критерий - модуль больше 10, мнимая часть отрицательна
    ComplexFunctor f;
    a.where(f)->LKP();
//map где действие - меняются местами мнимая и действительная части числа
    a.map(f)->LKP();
//задала дерево, которое объединю со старым
    BinaryTree<Complex> b;
    Complex b1(87.768, 875.624);
    Complex b2(90.138, 39.8043);
    b.Add(b1);
    b.Add(b2);
//объединение и вывод
    a.fusion(b)->LKP();
//вылеляю поддерево из первого дерева по значению элемента - корня будущего поддерева с проверкой на нуль-указатель
    if (a.SubTree(a4) != nullptr) a.SubTree(a4)->LKP();
//ищу существующий элемент
    if (a.SearchElement(a3)) {
        cout << "yes" << endl;
    } else cout << "no" << endl;
//ищу несуществующий элемент
    if (a.SearchElement(b1)) {
        cout << "yes" << endl;
    } else cout << "no" << endl;
//проверяю наличие поддерева в дереве
    BinaryTree<Complex>* c = a.fusion(b);
    if (c->contains(b)) {
        cout << "yes" << endl;
    } else cout << "no" << endl;
}
void testStudent(){
    BinaryTree<Student> a;
    Student first;
    a.Add(first);
    Student second("Konstantin", "Alekseevich", "Mikhhailov", 1998, 4557284, 1);
    a.Add(second);
    Student third("Aleksey", "Konstantinovich", "Semenenko", 1997, 4557395, 2);
    a.Add(third);
    Student forth("Tatiana", "Dmitrievna", "Semenova", 1996, 4550892, 3);
    a.Add(forth);
//добавила элементы
    a.LKP(); //вывод обхода лево-корень-право
    cout << a.LKPinS() << endl; //этот же обход, сохраненный в строку.
    a.LPK(); //лево-право-корень
    cout << a.LPKinS() << endl;
    a.KLP(); //корень-лево-право
    cout << a.KLPinS() << endl;
    a.KPL(); //корень-право-лево
    cout << a.KPLinS() << endl;
    a.PLK();//право-лево-корень
    cout << a.PLKinS() << endl;
    a.PKL(); //право-корень-лево
    cout << a.PKLinS() << endl;
//поиск выведенного элемента
    cout << forth << a.Find(forth)->value << endl;
//вывод высоты дерева
    cout << a.GetHeight() << endl;
//where где критерий - сравнение (выше по алфавиту или ниже) с "срединным" студентом "NNNNN OOOOO PPPPP"
    StudentFunctor f;
    a.where(f)->LKP();
//map где действия по сути нет. Возвращается дерево с теми же студентами
    a.map(f)->LKP();
//задала дерево, которое объединю со старым
    BinaryTree<Student> b;
    Student b1("Oleg", "Davidovich", "Volkov", 2000, 4559836, 1);
    b.Add(b1);
    Student b2("Margarita", "Sergeevna", "Razoomovskaya", 2001, 4550198, 1);
    b.Add(b2);
//объединение и вывод
    a.fusion(b)->LKP();
//вылеляю поддерево из первого дерева по значению элемента - корня будущего поддерева с проверкой на нуль-указатель
    if (a.SubTree(second) != nullptr) a.SubTree(second)->LKP();
//ищу существующий элемент
    if (a.SearchElement(third)) {
        cout << "yes" << endl;
    } else cout << "no" << endl;
//ищу несуществующий элемент
    if (a.SearchElement(b2)) {
        cout << "yes" << endl;
    } else cout << "no" << endl;
//проверяю наличие поддерева в дереве
    BinaryTree<Student>* c = a.fusion(b);
    if (c->contains(b)) {
        cout << "yes" << endl;
    } else cout << "no" << endl;
}
void testTeacher(){
    BinaryTree<Teacher> a;
    Teacher first;
    a.Add(first);
    Teacher second("Konstantin", "Alekseevich", "Mikhhailov", 1958, 3990111, 100000);
    a.Add(second);
    Teacher third("Aleksey", "Konstantinovich", "Semenenko", 1967, 3990222, 200000);
    a.Add(third);
    Teacher forth("Tatiana", "Dmitrievna", "Semenova", 1986, 3990333, 300000);
    a.Add(forth);
//добавила элементы
    a.LKP(); //вывод обхода лево-корень-право
    cout << a.LKPinS() << endl; //этот же обход, сохраненный в строку.
    a.LPK(); //лево-право-корень
    cout << a.LPKinS() << endl;
    a.KLP(); //корень-лево-право
    cout << a.KLPinS() << endl;
    a.KPL(); //корень-право-лево
    cout << a.KPLinS() << endl;
    a.PLK();//право-лево-корень
    cout << a.PLKinS() << endl;
    a.PKL(); //право-корень-лево
    cout << a.PKLinS() << endl;
//поиск выведенного элемента
    cout << forth << a.Find(forth)->value << endl;
//вывод высоты дерева
    cout << a.GetHeight() << endl;
//where где критерий - сравнение с "срединным" преподавателем "KKKKKKKK LLLLLLL MMMMMM"
    TeacherFunctor f;
    a.where(f)->LKP();
//map где действия по сути опять же нет
    a.map(f)->LKP();
//задала дерево, которое объединю со старым
    BinaryTree<Teacher> b;
    Teacher b1("Anna", "Denisovna", "Melnikova", 1989, 3990444, 150000);
    b.Add(b1);
    Teacher b2("Marina", "Vyacheslavovna", "Konovalova", 1974, 3990555, 250000);
    b.Add(b2);
//объединение и вывод
    a.fusion(b)->LKP();
//вылеляю поддерево из первого дерева по значению элемента - корня будущего поддерева с проверкой на нуль-указатель
    if (a.SubTree(second) != nullptr) a.SubTree(second)->LKP();
//ищу существующий элемент
    if (a.SearchElement(third)) {
        cout << "yes" << endl;
    } else cout << "no" << endl;
//ищу несуществующий элемент
    if (a.SearchElement(b2)) {
        cout << "yes" << endl;
    } else cout << "no" << endl;
//проверяю наличие поддерева в дереве
    BinaryTree<Teacher>* c = a.fusion(b);
    if (c->contains(b)) {
        cout << "yes" << endl;
    } else cout << "no" << endl;
}