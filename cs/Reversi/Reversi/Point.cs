using System;
using System.Collections.Generic;
using System.Text;

namespace Reversi
{
    public class Point
    {
        public Point() : this(0,0)
        {
        }

        public Point(int x, int y)
        {
            this.x = x;
            this.y = y;
        }

        public int x { get; set; }
        public int y { get; set; } 

    }
}
