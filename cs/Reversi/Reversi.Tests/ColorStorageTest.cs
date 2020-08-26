using NUnit.Framework;

namespace Reversi
{
    class ColorStorageTest
    {
        [Test]
        public void IntTest()
        {
            var c = new ColorStorage<int>();
            c[Color.BLACK] = 10;
            Assert.AreEqual(10, c[Color.BLACK]);
            c[Color.WHITE] = 20;
            Assert.AreEqual(20, c[Color.WHITE]);
            c[Color.EMPTY] = 30;
            Assert.AreEqual(30, c[Color.EMPTY]);
            
        }
    }
}
