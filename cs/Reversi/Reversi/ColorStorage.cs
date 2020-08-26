using System;
using System.Collections.Generic;
using System.Text;

namespace Reversi
{
    public class ColorStorage<T>
    {
        T[] data = new T[3];
        public T this[Color color]
        {
            get
            {
                return data[(int)color+1];
            }
            set
            {
                data[(int)color + 1] = value;
            }
        }
    }
}
