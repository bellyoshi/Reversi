using System;
using System.Collections.Generic;
using System.Text;

namespace Reversi
{
    public class Cells
    {
        public int ColSize { get; private set; }
        public int RowSize { get; private set; }

        Color[] RawBoard;

        public void Init()
        {
            for (int i = ColSize + 1; i < RawBoard.Length - ColSize; i++)
            {
                RawBoard[i] = Color.EMPTY;
            }
            for (int x = 0; x < ColSize; x++)
            {
                this[x, 0] = Color.WALL;
                this[x, RowSize - 1]  = Color.WALL;
            }
            for (int y = 0; y < RowSize; y++)
            {
                this[0, y]=  Color.WALL;
                this[ColSize - 1, y] =  Color.WALL;
            }
        }

        public Cells(int size)
        {
            this.RowSize = size + 2;
            this.ColSize = size + 2;
            this.RawBoard = new Color[RowSize * ColSize];
        }

        public int GetIndex(Point p)
        {
            return GetIndex(p.x, p.y);
        }
        public int GetIndex(int x, int y)
        {
            return y * ColSize + x;
        }

        public Color this[Point p]
        {
            get
            {
                return this[p.x, p.y];
            }
            set
            {
                this[p.x, p.y] = value;
            }
        }
        public Color this[int p]
        {
            get
            {
                return RawBoard[p];
            }
            set
            {
                RawBoard[p] = value;
            }
        }
        public Color this[int x,int y]
        {
            
            get
            {
                return RawBoard[GetIndex(x, y)];
            }
            set
            {
                RawBoard[GetIndex(x, y)] = value;
            }
        }
    }
}
