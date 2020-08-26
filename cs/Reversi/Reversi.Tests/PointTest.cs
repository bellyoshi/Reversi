using NUnit.Framework;

namespace Reversi
{
    
    class PointTest
    {
        [Test]
        public void PointZeroTest()
        {
            var p = new Point();
            Assert.AreEqual(0, p.x);
            Assert.AreEqual(0, p.y);
        }

        [Test]
        public void Point45Test()
        {
            var p = new Point(4, 5);
            Assert.AreEqual(4, p.x);
            Assert.AreEqual(5, p.y);
        }
    }
}
