using System;
using System.Collections.Generic;
using System.Text;

namespace Reversi
{
    public class Disc : Point
    {
        public Color color { get; set; }
        public Disc() : base(0, 0)
        {
            color = Color.EMPTY;
        }
        public Disc(int x, int y, Color color) : base(x, y)
        {
            this.color = color;
        }
    }
}
