using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Drawing;

namespace WindowsFormsApp1
{
    class Poligon
    {
        private List<PointF> points;

        public Poligon()
        {
            points = new List<PointF>();
        }

        public void AddPoint(PointF point)
        {
            /* Trebuie sa sortam prin insertie lista in functie de y */
            points.Add(point);
        }

        public void RemovePoint()
        {
            try
            {
                points.Remove(points[points.Count - 1]);
            }
            catch (ArgumentOutOfRangeException ex)
            {
            }
        }

        public void RemovePoint(int index)
        {
            points.Remove(points[index]);
        }

        public int GetNumberOfPoints()
        {
            return points.Count;
        }

        public PointF GetPointAt(int index)
        {
            return points[index];
        }

        private int GetLowestXIndex()
        {

            double lowestX = points[0].X;
            int index = 0;

            for (int i = 1; i < points.Count; ++i)
            {
                if (points[i].X < lowestX)
                {
                    index = i;
                    lowestX = points[i].X;
                }

            }
            return index;
        }

        private double GetPolarAngle(PointF point)
        {
            /* Compute the polar angle of our point, which is equal to arctan(y / x) */
            double polar = Math.Atan(point.Y / point.X);
            if (polar > 0.0)
            {
                return polar;
            }

            return polar + Math.PI;
        }

        private List<PointF> SortByPolarAngle()
        {
            int n = points.Count;
            int[] cadran=new int[n];
            int[] ordine = new int[n];
            List<PointF> sortedPoints = new List<PointF>();

            for(int i=0;i<n;i++)
            {
                ordine[i] = i;

                if (points[i].X >= 0 && points[i].Y >= 0)
                    cadran[i] = 1;

                if (points[i].X <= 0 && points[i].Y >= 0)
                    cadran[i] = 2;

                if (points[i].X <= 0 && points[i].Y <= 0)
                    cadran[i] = 3;

                if (points[i].X >= 0 && points[i].Y <= 0)
                    cadran[i] = 4;
               

            }


                for (int i = 0; i < n - 1; i++)
                {
                    for (int j = i + 1; j < n; j++)
                    {

                        double a, b;
                    a = GetPolarAngle(points[ordine[i]]) * cadran[ordine[i]]+1; //+ ((cadran[ordine[i]] - 1 ) * 90)* (Math.PI / 180);
                    b = GetPolarAngle(points[ordine[j]]) * cadran[ordine[j]]+1;// + ((cadran[ordine[j]] - 1 ) * 90)* (Math.PI / 180);
                          //  System.Windows.Forms.MessageBox.Show(a.ToString() + "    ,    " + b.ToString());
                            if (a > b)
                            {
                                int e;
                                e = ordine[i];
                                ordine[i] = ordine[j];
                                ordine[j] = e;

                                e = cadran[ordine[i]];
                                cadran[ordine[i]] = cadran[ordine[j]];
                                cadran[ordine[j]] = e;
                            }

                    }
                }


                for (int i = 0; i < n; i++)
                sortedPoints.Add(points[ordine[i]]);
            return sortedPoints;
        }

        private int OrientationTest(PointF p1, PointF p2, PointF p3)
        {
            
            double value = (p2.Y - p1.Y) * (p3.X - p1.X) - (p2.X - p1.X) * (p3.Y - p1.Y);

            /*  COLINIAR */
            if (value == 0)
                return 0;
            
            /* RIGHT TURN */
            if (value > 0)
                return 1;

            /* LEFT TURN */
            return 2;
        }

        private PointF HighestY(PointF p1, PointF p2)
        {
            if (Math.Abs(p1.Y) > Math.Abs(p2.Y))
                return p1;
            else if (Math.Abs(p2.Y) > Math.Abs(p1.Y))
                return p2;
            else
            {
                /* If they have the same Y value, we return the one with the greatest absolute X value */
                if (Math.Abs(p1.X) > Math.Abs(p2.X))
                    return p1;

                return p2;
            }
        }

        private Poligon UpdateHull(Poligon hull, List<PointF> sortedPoints, int index)
        {

            int hullSize = hull.GetNumberOfPoints();
            int orientation = OrientationTest(hull.GetPointAt(hullSize - 2), hull.GetPointAt(hullSize - 1), sortedPoints[index]);

            if (orientation == 2)
            {
                hull.AddPoint(sortedPoints[index]);
                Console.Write(sortedPoints[index].X + " " + sortedPoints[index].Y);
            }

            else if (orientation == 1)
            {
                hull.RemovePoint();
                hull.AddPoint(sortedPoints[index]);
                Console.Write(sortedPoints[index].X + " " + sortedPoints[index].Y);
            }

            else
            {
                PointF furthestPoint = HighestY(hull.GetPointAt(hullSize - 1), sortedPoints[index]);
                hull.RemovePoint();
                hull.AddPoint(furthestPoint);
                Console.Write(furthestPoint.X + " " + furthestPoint.Y);
            }
    
            return hull;
        }

        public Poligon GenerateHull()
        {
           
            Poligon hull = new Poligon();

            //  List<PointF> sortedPoints = SortByPolarAngle();
            //// for(int i=0;i<sortedPoints.Count;i++)
            //  //    System.Windows.Forms.MessageBox.Show(sortedPoints[i].X + "    ,    " + sortedPoints[i].Y);

            //  hull.AddPoint(sortedPoints[0]);
            //  hull.AddPoint(sortedPoints[1]);
            //  for (int i = 2; i < sortedPoints.Count; ++i)
            //  {
            //      UpdateHull(hull, sortedPoints, i);
            //  }

            //  int hullSize = hull.GetNumberOfPoints();
            //  int orientation = OrientationTest(hull.GetPointAt(hullSize - 1) ,hull.GetPointAt(0), hull.GetPointAt(1));

            //  if (orientation == 1 || orientation == 0)
            //  {
            //      hull.RemovePoint(0);
            //  }
            //  hull.AddPoint(hull.points[0]);

            int lowestXIndex = GetLowestXIndex();
            int currentIndex = lowestXIndex;

            do
            {
                hull.AddPoint(points[currentIndex]);

                int nextIndex = (currentIndex + 1) % points.Count;
                for (int i = 0; i < points.Count; ++i)
                {
                    if (OrientationTest(points[currentIndex], points[i], points[nextIndex]) == 2)
                    {
                        nextIndex = i;
                    }
                }

                currentIndex = nextIndex;

            } while (currentIndex != lowestXIndex);
            return hull;
        }
    }
}
