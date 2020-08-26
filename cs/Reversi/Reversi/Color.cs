using System;
using System.Collections.Generic;
using System.Text;

namespace Reversi
{
    public enum Color
    {
        BLACK = 1,
        EMPTY = 0,
        WHITE = -1,
        WALL = 2
    }
    static public  class ColorExtention
    {
        public static Color Reverse(this Color color)
        {
            var c = -(int)color;
            return (Color)Enum.ToObject(typeof(Color),c);
        } 
    }
}
