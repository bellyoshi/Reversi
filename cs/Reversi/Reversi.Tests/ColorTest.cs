using NUnit.Framework;

namespace Reversi
{
    
    class ColorTest
    {
        [Test]
        public void ColorValueTest()
        {
            Assert.AreEqual(Color.BLACK.Reverse(), Color.WHITE);
            Assert.AreEqual(Color.WHITE.Reverse(), Color.BLACK); 
            Assert.AreEqual(Color.EMPTY.Reverse(), Color.EMPTY);
            //Color.WALL.Reverse();  未定義
        }
    }
}
