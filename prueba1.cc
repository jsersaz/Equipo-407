#include <actividad.h>
#include <funciones.h>
#include <string>
#include <list>
#include <gtest/gtest.h>
//#include <gmock/gmock.h>
//using ::testing::StartsWith;


TEST(Actividad, AddList) {
  Actividad a1("10");
  Actividad a2("11");
  std::list <Actividad> act_list;
  AddList(a1, act_list);
  EXPECT_EQ(true, FindList(a1.GetActId(), act_list));
  EXPECT_EQ(false, FindList(a2.GetActId(), act_list));
}


TEST(Actividad, DeleteList) {
    Actividad a1("10");
    Actividad a2("11");
    std::list <Actividad> act_list;
    act_list.push_back(a1);
    act_list.push_back(a2);
    DeleteList(a1, act_list);
    EXPECT_EQ(false, FindList(a1.GetActId(), act_list));
    EXPECT_EQ(true, FindList(a2.GetActId(), act_list));

}

TEST(CheckStringN) {
    std::string cad1="hola";
    std::string cad2="1";
    std::string cad3="hola mundo";
    std::string cad4="123hola";
    std::string cad5="";
    int aux;
    EXPECT_EQ(false, CheckStringN(cad1, aux));
    EXPECT_EQ(true, CheckStringN(cad2, aux));
    EXPECT_EQ(false, CheckStringN(cad3, aux));
    EXPECT_EQ(false, CheckStringN(cad4, aux));
    EXPECT_EQ(false, CheckStringN(cad5, aux));

}

TEST(TurnInt) {
    std::string cad1="2045";
    std::string cad2="1";

    EXPECT_EQ(2045, TurnInt(cad1));
    EXPECT_EQ(1, TurnInt(cad2));
}


