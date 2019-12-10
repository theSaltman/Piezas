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

/*dropPiece(int column) tests*/

TEST(PiezasTest, dropPieceOver) {
	Piezas board;
	ASSERT_EQ(board.dropPiece(4), Invalid);
}
TEST(PiezasTest, dropPieceUnder) {
	Piezas board;
	ASSERT_EQ(board.dropPiece(-1), Invalid);
}

TEST(PiezasTest, dropPieceColumn00) {
	Piezas board;
	ASSERT_EQ(board.dropPiece(0), X);
}
TEST(PiezasTest, dropPieceColumn01) {
	Piezas board;
	board.dropPiece(0);
	ASSERT_EQ(board.dropPiece(0), O);
}
TEST(PiezasTest, dropPieceColumn02) {
	Piezas board;
	board.dropPiece(0);
	board.dropPiece(0);
	ASSERT_EQ(board.dropPiece(0), X);
}
TEST(PiezasTest, dropPieceColumn0ColFull) {
	Piezas board;
	board.dropPiece(0);
	board.dropPiece(0);
	board.dropPiece(0);
	ASSERT_EQ(board.dropPiece(0), Blank);
}
TEST(PiezasTest, dropPieceColumn0ColFullTurnStillChanges) {
	Piezas board;
	board.dropPiece(0);
	board.dropPiece(0);
	board.dropPiece(0);
	board.dropPiece(0);
	ASSERT_EQ(board.dropPiece(1), X);
}

TEST(PiezasTest, dropPieceColumn10) {
	Piezas board;
	ASSERT_EQ(board.dropPiece(1), X);
}
TEST(PiezasTest, dropPieceColumn11) {
	Piezas board;
	board.dropPiece(1);
	ASSERT_EQ(board.dropPiece(1), O);
}
TEST(PiezasTest, dropPieceColumn12) {
	Piezas board;
	board.dropPiece(1);
	board.dropPiece(1);
	ASSERT_EQ(board.dropPiece(1), X);
}
TEST(PiezasTest, dropPieceColumn1ColFull) {
	Piezas board;
	board.dropPiece(1);
	board.dropPiece(1);
	board.dropPiece(1);
	ASSERT_EQ(board.dropPiece(1), Blank);
}
TEST(PiezasTest, dropPieceColumn1ColFullTurnStillChanges) {
	Piezas board;
	board.dropPiece(1);
	board.dropPiece(1);
	board.dropPiece(1);
	board.dropPiece(1);
	ASSERT_EQ(board.dropPiece(0), X);
}

TEST(PiezasTest, dropPieceColumn20) {
	Piezas board;
	ASSERT_EQ(board.dropPiece(2), X);
}
TEST(PiezasTest, dropPieceColumn21) {
	Piezas board;
	board.dropPiece(2);
	ASSERT_EQ(board.dropPiece(2), O);
}
TEST(PiezasTest, dropPieceColumn22) {
	Piezas board;
	board.dropPiece(2);
	board.dropPiece(2);
	ASSERT_EQ(board.dropPiece(2), X);
}
TEST(PiezasTest, dropPieceColumn2ColFull) {
	Piezas board;
	board.dropPiece(2);
	board.dropPiece(2);
	board.dropPiece(2);
	ASSERT_EQ(board.dropPiece(2), Blank);
}
TEST(PiezasTest, dropPieceColumn2ColFullTurnStillChanges) {
	Piezas board;
	board.dropPiece(2);
	board.dropPiece(2);
	board.dropPiece(2);
	board.dropPiece(2);
	ASSERT_EQ(board.dropPiece(0), X);
}

TEST(PiezasTest, dropPieceColumn30) {
	Piezas board;
	ASSERT_EQ(board.dropPiece(3), X);
}
TEST(PiezasTest, dropPieceColumn31) {
	Piezas board;
	board.dropPiece(3);
	ASSERT_EQ(board.dropPiece(3), O);
}
TEST(PiezasTest, dropPieceColumn32) {
	Piezas board;
	board.dropPiece(3);
	board.dropPiece(3);
	ASSERT_EQ(board.dropPiece(3), X);
}
TEST(PiezasTest, dropPieceColumn3ColFull) {
	Piezas board;
	board.dropPiece(3);
	board.dropPiece(3);
	board.dropPiece(3);
	ASSERT_EQ(board.dropPiece(3), Blank);
}
TEST(PiezasTest, dropPieceColumn3ColFullTurnStillChanges) {
	Piezas board;
	board.dropPiece(3);
	board.dropPiece(3);
	board.dropPiece(3);
	board.dropPiece(3);
	ASSERT_EQ(board.dropPiece(0), X);
}

/*pieceAt(int row, int column) tests*/
TEST(PiezasTest, pieceAt00Blank) {
	Piezas board;
	ASSERT_EQ(board.pieceAt(0,0), Blank);
}
TEST(PiezasTest, pieceAt01Blank) {
	Piezas board;
	ASSERT_EQ(board.pieceAt(0,1), Blank);
}
TEST(PiezasTest, pieceAt02Blank) {
	Piezas board;
	ASSERT_EQ(board.pieceAt(0,2), Blank);
}
TEST(PiezasTest, pieceAt03Blank) {
	Piezas board;
	ASSERT_EQ(board.pieceAt(0,3), Blank);
}
TEST(PiezasTest, pieceAt10Blank) {
	Piezas board;
	ASSERT_EQ(board.pieceAt(1,0), Blank);
}
TEST(PiezasTest, pieceAt11Blank) {
	Piezas board;
	ASSERT_EQ(board.pieceAt(1,1), Blank);
}
TEST(PiezasTest, pieceAt12Blank) {
	Piezas board;
	ASSERT_EQ(board.pieceAt(1,2), Blank);
}
TEST(PiezasTest, pieceAt13Blank) {
	Piezas board;
	ASSERT_EQ(board.pieceAt(1,3), Blank);
}
TEST(PiezasTest, pieceAt20Blank) {
	Piezas board;
	ASSERT_EQ(board.pieceAt(2,0), Blank);
}
TEST(PiezasTest, pieceAt21Blank) {
	Piezas board;
	ASSERT_EQ(board.pieceAt(2,1), Blank);
}
TEST(PiezasTest, pieceAt22Blank) {
	Piezas board;
	ASSERT_EQ(board.pieceAt(2,2), Blank);
}
TEST(PiezasTest, pieceAt23Blank) {
	Piezas board;
	ASSERT_EQ(board.pieceAt(2,3), Blank);
}

TEST(PiezasTest, pieceAt00X) {
	Piezas board;
	board.dropPiece(0);
	ASSERT_EQ(board.pieceAt(0,0), X);
}
TEST(PiezasTest, pieceAt10X) {
	Piezas board;
	board.dropPiece(0);
	board.dropPiece(1);
	board.dropPiece(0);
	ASSERT_EQ(board.pieceAt(1,0), X);
}

TEST(PiezasTest, pieceAt00O) {
	Piezas board;
	board.dropPiece(1);
	board.dropPiece(0);
	ASSERT_EQ(board.pieceAt(0,0), O);
}
TEST(PiezasTest, pieceAt10O) {
	Piezas board;
	board.dropPiece(0);
	board.dropPiece(1);
	board.dropPiece(1);
	board.dropPiece(0);
	ASSERT_EQ(board.pieceAt(1,0), X);
}

TEST(PiezasTest, pieceAtRowUnder) {
	Piezas board;
	ASSERT_EQ(board.pieceAt(-1,0), Invalid);
}
TEST(PiezasTest, pieceAtRowOver) {
	Piezas board;
	ASSERT_EQ(board.pieceAt(3,0), Invalid);
}
TEST(PiezasTest, pieceAtColUnder) {
	Piezas board;
	ASSERT_EQ(board.pieceAt(0,-1), Invalid);
}
TEST(PiezasTest, pieceAtColOver) {
	Piezas board;
	ASSERT_EQ(board.pieceAt(0,4), Invalid);
}
