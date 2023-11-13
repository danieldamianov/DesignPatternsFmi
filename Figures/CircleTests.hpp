#ifndef __LIST_TESTS_HPP
#define __LIST_TESTS_HPP

#include "doctest.h"
#include <memory>
#include "StringFigureFactory.h"

TEST_CASE("Test circle radius")
{
	IFigureFactory* factory = new StringFigureFactory("circle 4");

	const double PI = 4 * atan(1);

	Figure* circle = factory->createFigure();
	CHECK_EQ(circle->getRepresentativeName(), "circle");
	CHECK(Figure::checkDoublesForEquality(circle->getPerimeter(), 2 * PI * 4));

	factory->recycleFigure(circle);

	delete factory;
}

TEST_CASE("Test cloning triangle")
{
	IFigureFactory* factory = new StringFigureFactory("triangle 4 3 6");
	Figure* triangle = factory->createFigure();

	std::unique_ptr<Figure> clonedTriangle = triangle->clone();

	CHECK(triangle->equals(*clonedTriangle));

	factory->recycleFigure(triangle);
	delete factory;
}

TEST_CASE("Test equal function")
{
	IFigureFactory* factory1 = new StringFigureFactory("triangle 4 3 6");
	IFigureFactory* factory2 = new StringFigureFactory("triangle 6 3 4");
	IFigureFactory* factory3 = new StringFigureFactory("triangle 6 10 4");

	Figure* triangle1 = factory1->createFigure();
	Figure* triangle2 = factory2->createFigure();
	Figure* triangle3 = factory3->createFigure();

	CHECK(triangle1->equals(*triangle2));
	CHECK(triangle1->equals(*triangle3) == false);

	factory1->recycleFigure(triangle1);
	factory2->recycleFigure(triangle2);
	factory3->recycleFigure(triangle3);

	delete factory1;
	delete factory2;
	delete factory3;
}


#endif

//#define AllLists ForwardList<int>, List<int>

//TEST_CASE_TEMPLATE("��� ��������� �� ������ ��� � ������",
//    List, AllLists)
//{
//    List l;
//    CHECK(l.empty());
//}
//
//TEST_CASE_TEMPLATE("��� �������� �� ������� � ������ ��� ���� �� � ������",
//    List, AllLists)
//{
//    List l;
//    l.push_back(42);
//    CHECK(!l.empty());
//}
//
//TEST_CASE_TEMPLATE("�������������� �������� �� �������� � ������� � ����������� ��",
//    List, AllLists)
//{
//    List l;
//    for (int i = 1; i <= 10; i++)
//        l.push_back(i);
//
//    int i = 1;
//    for (int x : l)
//        CHECK_EQ(i++, x);
//    CHECK_EQ(i, 11);
//}
//
//TEST_CASE_TEMPLATE("�������������� �������� �� �������� � ������� �� �������� � ����������� ��",
//    List, AllLists)
//{
//    List l;
//    for (int i = 1; i <= 10; i++)
//        l.push_front(i);
//
//    int i = 10;
//    for (int x : l)
//        CHECK_EQ(i--, x);
//    CHECK_EQ(i, 0);
//}
//
//TEST_CASE_TEMPLATE("��������� �� �������� �� ����� �������",
//    List, AllLists)
//{
//    List l;
//    for (int i = 1; i <= 10; i += 2)
//        l.push_back(i);
//
//    for (typename List::Iterator it = l.begin(); it != l.end(); ++it, ++it)
//        l.insertAfter(it, *it + 1);
//
//    int i = 1;
//    for (int x : l)
//        CHECK_EQ(i++, x);
//    CHECK_EQ(i, 11);
//}
//
//TEST_CASE_TEMPLATE("�������������� ��������� �� ��������� ������� � �������",
//    List, AllLists)
//{
//    List l;
//    for (int i = 1; i <= 10; i++)
//        l.push_front(i);
//
//    int x;
//    for (int i = 10; i >= 1; i--)
//    {
//        CHECK_EQ(l.front(), i);
//        l.pop_front();
//    }
//    CHECK(l.empty());
//}
//
//TEST_CASE_TEMPLATE("�������������� ��������� �� ������ ������� � �������",
//    List, AllLists)
//{
//    List l;
//    for (int i = 1; i <= 10; i++)
//        l.push_back(i);
//
//    for (int i = 1; i <= 10; i++)
//    {
//        CHECK_EQ(l.front(), i);
//        l.pop_front();
//    }
//    CHECK(l.empty());
//}
//
//TEST_CASE_TEMPLATE("�������� ��������� �� ������������ �� ��������",
//    List, AllLists)
//{
//    List l1;
//    for (int i = 1; i <= 10; i++)
//        l1.push_back(i);
//
//    List l2 = l1;
//    int i = 1;
//    CHECK_EQ(l2.front(), i);
//    l2.pop_front();
//
//    for (; i <= 9; i++)
//    {
//        CHECK_EQ(l1.front(), i);
//        l1.pop_front();
//        CHECK_EQ(l2.front(), i + 1);
//        l2.pop_front();
//    }
//    CHECK_EQ(l1.front(), i);
//    l1.pop_front();
//    CHECK(l1.empty());
//    CHECK(l2.empty());
//}
//
//TEST_CASE_TEMPLATE("�������� ��������� �� ��������� �� �����������",
//    List, AllLists)
//{
//    List l1;
//    for (int i = 1; i <= 10; i++)
//        l1.push_back(i);
//    List l2;
//    for (int i = 7; i <= 27; i++)
//        l2.push_back(i);
//
//    l2 = l1;
//    int i = 1;
//    CHECK_EQ(l2.front(), i);
//    l2.pop_front();
//
//    for (; i <= 9; i++)
//    {
//        CHECK_EQ(l1.front(), i);
//        l1.pop_front();
//        CHECK_EQ(l2.front(), i + 1);
//        l2.pop_front();
//    }
//    CHECK_EQ(l1.front(), i);
//    l1.pop_front();
//    CHECK(l1.empty());
//    CHECK(l2.empty());
//}
//
//TEST_CASE("�������������� �������� �� �������� � ���������� ������ � ����������� �� ����� ������")
//{
//    List<int> l;
//    for (int i = 1; i <= 10; i++)
//        l.push_back(i);
//
//    SUBCASE("iterator")
//    {
//        int i = 1;
//        for (List<int>::Iterator it = l.begin(); it; ++it)
//            CHECK_EQ(*it, i++);
//        CHECK_EQ(i, 11);
//    }
//
//    SUBCASE("reverse iterator")
//    {
//        int i = 10;
//        for (List<int>::ReverseIterator it = l.rbegin(); it; ++it)
//            CHECK_EQ(*it, i--);
//        CHECK_EQ(i, 0);
//    }
//}
