using NUnit.Framework;


namespace Reversi
{
    class BoardTest
    {
        [Test]
        public void InitTest()
        {
            var b = new Board();
            for(int x = 0; x < b.cells.ColSize; x++)
            {
                for(int y = 0; y < b.cells.RowSize; y++)
                {
                    b.cells[x, y] = Color.BLACK;
                }
            }
            b.Init();
            var pattern = new int[][] {
                new int[] { 2, 2, 2, 2, 2, 2, 2, 2, 2, 2 },
                new int[] { 2, 0, 0, 0, 0, 0, 0, 0, 0, 2 },
                new int[] { 2, 0, 0, 0, 0, 0, 0, 0, 0, 2 },
                new int[] { 2, 0, 0, 0, 0, 0, 0, 0, 0, 2 },
                new int[] { 2, 0, 0, 0,-1, 1, 0, 0, 0, 2 },
                new int[] { 2, 0, 0, 0, 1,-1, 0, 0, 0, 2 },
                new int[] { 2, 0, 0, 0, 0, 0, 0, 0, 0, 2 },
                new int[] { 2, 0, 0, 0, 0, 0, 0, 0, 0, 2 },
                new int[] { 2, 0, 0, 0, 0, 0, 0, 0, 0, 2 },
                new int[] { 2, 2, 2, 2, 2, 2, 2, 2, 2, 2 }};
            for(int y = 0; y < pattern.Length; y++)
            {
                for(int x = 0; x < pattern[y].Length; x++)
                {
                    Assert.AreEqual(pattern[y][x], (int)b.cells[x, y],$"{x},{y}");
                }
            }
        }
        [Test]
        public void CheckMobirityTest()
        {
            var b = new Board();
            b.Init();
            Assert.AreEqual(0, b.CheckMobirity(new Disc(0, 0, Color.BLACK)));
            Assert.AreEqual(0, b.CheckMobirity(new Disc(1, 1, Color.BLACK)));
            Assert.AreEqual(0b00010000, b.CheckMobirity(new Disc(4, 3, Color.BLACK)));
            Assert.AreEqual(0b00010000, b.CheckMobirity(new Disc(5, 3, Color.WHITE)));
            Assert.AreEqual(0b01000000, b.CheckMobirity(new Disc(3, 5, Color.WHITE)));
        }
    }
}
