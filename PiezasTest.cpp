/**
 * Unit Tests for Piezas
**/

#include <gtest/gtest.h>
#include "Piezas.h"
 
class PiezasTest : public ::testing::Test
{
	protected:
		PiezasTest(){} //constructor runs before each test
		virtual ~PiezasTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor) 
};

/*reset() tests*/

TEST(PiezasTest, reset00) {
	Piezas board;
	board.reset();
	ASSERT_EQ(board.pieceAt(0,0), Blank);
}
TEST(PiezasTest, reset01) {
	Piezas board;
	board.reset();
	ASSERT_EQ(board.pieceAt(0,1), Blank);
}
TEST(PiezasTest, reset02) {
	Piezas board;
	board.reset();
	ASSERT_EQ(board.pieceAt(0,2), Blank);
}
TEST(PiezasTest, reset03)
{
	Piezas board;
	board.reset();
	ASSERT_EQ(board.pieceAt(0,3), Blank);
}
TEST(PiezasTest, reset10)
{
	Piezas board;
	board.reset();
	ASSERT_EQ(board.pieceAt(1,0), Blank);
}
TEST(PiezasTest, reset11)
{
	Piezas board;
	board.reset();
	ASSERT_EQ(board.pieceAt(1,1), Blank);
}
TEST(PiezasTest, reset12)
{
	Piezas board;
	board.reset();
	ASSERT_EQ(board.pieceAt(1,2), Blank);
}
TEST(PiezasTest, reset13)
{
	Piezas board;
	board.reset();
	ASSERT_EQ(board.pieceAt(1,3), Blank);
}
TEST(PiezasTest, reset20)
{
	Piezas board;
	board.reset();
	ASSERT_EQ(board.pieceAt(2,0), Blank);
}
TEST(PiezasTest, reset21)
{
	Piezas board;
	board.reset();
	ASSERT_EQ(board.pieceAt(2,1), Blank);
}
TEST(PiezasTest, reset22)
{
	Piezas board;
	board.reset();
	ASSERT_EQ(board.pieceAt(2,2), Blank);
}
TEST(PiezasTest, reset23)
{
	Piezas board;
	board.reset();
	ASSERT_EQ(board.pieceAt(2,3), Blank);
}
TEST(PiezasTest, resetColOver) {
	Piezas board;
	board.reset();
	ASSERT_EQ(board.pieceAt(0,4), Invalid);
}
TEST(PiezasTest, resetColUnder) {
	Piezas board;
	board.reset();
	ASSERT_EQ(board.pieceAt(0,-1), Invalid);
}
TEST(PiezasTest, resetRowOver) {
	Piezas board;
	board.reset();
	ASSERT_EQ(board.pieceAt(3,0), Invalid);
}
TEST(PiezasTest, resetRowUnder) {
	Piezas board;
	board.reset();
	ASSERT_EQ(board.pieceAt(-1,0), Invalid);
}
