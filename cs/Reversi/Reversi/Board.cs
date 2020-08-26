using System;
using System.Collections.Generic;
using System.Text;

namespace Reversi
{
    public class Board
    {
        const int MAX_TURNS = 60;
        const int BOARD_SIZE = 8;

        public Cells cells = new Cells(BOARD_SIZE);
        public Board()
        {
            DirectionInit();
        }

        void DirectionInit()
        {
            int upper = cells.GetIndex(0, -1);
            int left = cells.GetIndex(-1, 0);
            int right = cells.GetIndex(1, 0);
            int lower = cells.GetIndex(0, 1);

            Directions = new int[] {
                upper,
                upper+left,
                left,
                lower+left,
                lower,
                lower+right,
                right,
                upper+right
            };
        }

        int[] Directions;
        public int TurnCount { get; private set; }
        public Color CurrentColor { get; private set; }

        private List<Disc> UpdateLog = new List<Disc>();

        private ColorStorage<int> DiscsCount = new ColorStorage<int>();
        private List<List<Point>>[] MovablePos = new List<List<Point>>[MAX_TURNS];

        public int CheckMobirity(Disc disc)
        {
            if(cells[disc] != Color.EMPTY) return 0;
   
            var revcolor = disc.color.Reverse();
            int allMobirity = 0;
            var dirMobirity = 1;
            foreach (var dir in Directions)
            {
                int p = cells.GetIndex(disc) + dir;
                if (cells[p] == revcolor)
                {
                    p += dir;
                    while (cells[p] == revcolor) p+=dir;
                    if (cells[p] == disc.color) allMobirity |= dirMobirity;
                }
                dirMobirity <<= 1;
            }
            return allMobirity;
       }
 

        public void Init()
        {
            cells.Init();
            cells[4, 5] = Color.BLACK;
            cells[5, 4] = Color.BLACK;
            cells[5, 5] = Color.WHITE;
            cells[4, 4] = Color.WHITE;
        }


        bool Move(Point point)
        {
            return false;
        }
        public void Undo() { }

        public void Pass() { }


        public bool IsGameOver()
        {
            return false;
        }


    }
}
