#include <actividad.h>
#include <preinscripcion.h>
#include <inscripcion.h>
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

TEST(Inscripcion, Añadir_inscripción){
	std::list <Inscripcion> ins_list;
	Inscripcion i(1);
	EXPECT_EQ(true, AddListIns(i,ins_list));
	Inscripcion a(1);
	EXPECT_EQ(false, AddListIns(a,ins_list));
}

TEST(Inscripcion, Borrar_inscripción){
	std::list <Inscripcion> ins_list;
	Inscripcion i(1);
	AddListIns(Inscripcion i,std::list <Inscripcion> &ins_list)
	EXPECT_EQ(true, DeleteListIns(i,ins_list));
	Inscripcion a(1);
	EXPECT_EQ(false, DeleteListIns(a,ins_list));
}

TEST(Preinscripcion, Cambiar_estado){
	std::list <Preinscripcion> pre_list;
	Preinscripcion p1(1, 1, "User1", false, true);
	Preinscripcion p2(2, 2, "User2", false, false);
	AddListPre(p1,pre_list);
	AddListPre(p2,pre_list);
	EXPECT_EQ(true, ChangeStatus(p1.GetPreId(), pre_list));
	EXPECT_EQ(false, ChangeStatus(p2.GetPreId(), pre_list));
}

TEST(Preinscripcion, Añadir_preinscripción){
	std::list <Preinscripcion> pre_list;
	Preinscripcion p(1);
	EXPECT_EQ(true, AddListPre(p,pre_list));
	Preinscripcion e(1);
	EXPECT_EQ(false, AddListPre(e,pre_list));
}
