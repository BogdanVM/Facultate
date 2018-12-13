using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Windows.Forms.DataVisualization.Charting;
using System.Windows.Input;

namespace WindowsFormsApp1
{
    public partial class Form1 : Form
    {
        Poligon poligon;
        Poligon acoperireConvexa;

        int numberOfClicks = 0;

        public Form1()
        {
            InitializeComponent();
   
            poligon = new Poligon();
            acoperireConvexa = new Poligon();
            
        }

        private void InitChart()
        {
            grafic.ChartAreas[0].AxisX.MajorGrid.LineWidth = 0;
            grafic.ChartAreas[0].AxisY.MajorGrid.LineWidth = 0;

            grafic.ChartAreas[0].AxisX.Crossing = 0;
            grafic.ChartAreas[0].AxisY.Crossing = 0;

            grafic.ChartAreas[0].AxisX.ArrowStyle = AxisArrowStyle.Lines;
            grafic.ChartAreas[0].AxisY.ArrowStyle = AxisArrowStyle.Lines;

            grafic.ChartAreas[0].AxisX.Maximum = 20;
            grafic.ChartAreas[0].AxisY.Maximum = 20;

            grafic.ChartAreas[0].AxisX.Minimum = -20;
            grafic.ChartAreas[0].AxisY.Minimum = -20;

            grafic.ChartAreas[0].AxisX.Interval = 8;
            grafic.ChartAreas[0].AxisY.Interval = 8;
            

        }

        private void AddSeries(SeriesChartType type, string name)
        {
            Series series = new Series();
            series.ChartType = type;
            series.Name = name;

            if (type == SeriesChartType.Line)
            {
                series.BorderWidth = 3;
            }
            else if (name.Equals("Puncte poligon"))
            {
                series.Points.AddXY(0, 0);
                series.MarkerSize = 7;
                series.MarkerStyle = MarkerStyle.Circle;
                series.Color = Color.Red;
            }
            grafic.Series.Add(series);
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            
            InitChart();
            AddSeries(SeriesChartType.Line, "Acoperire convexa");
            AddSeries(SeriesChartType.Point, "Puncte poligon");
            grafic.Series["Puncte poligon"].Points[0].Color = Color.Transparent;

            AddSeries(SeriesChartType.Point, "Puncte acoperire convexa");
            grafic.Series["Puncte acoperire convexa"].Color = Color.SeaGreen;
            grafic.Series["Puncte acoperire convexa"].MarkerSize = 9;
            grafic.Series["Puncte acoperire convexa"].MarkerStyle = MarkerStyle.Circle;
        }

        private bool ClickOutsideChartArea(double x, double y)
        {

            double minX, maxX;
            double minY, maxY;

            minX = grafic.ChartAreas[0].AxisX.Minimum;
            maxX = grafic.ChartAreas[0].AxisX.Maximum;

            minY = grafic.ChartAreas[0].AxisY.Minimum;
            maxY = grafic.ChartAreas[0].AxisY.Maximum;

            if (x < minX || x > maxX || y < minY || y > maxY)
                return true;

            return false;
        }

        private void grafic_MouseClick(object sender, MouseEventArgs e)
        {
            if (numberOfClicks++ == 0)
            {
                grafic.Series["Puncte poligon"].Points.Clear();
            }

            double x = grafic.ChartAreas[0].AxisX.PixelPositionToValue(e.X);
            double y = grafic.ChartAreas[0].AxisY.PixelPositionToValue(e.Y);

            if (ClickOutsideChartArea(x, y) == false)
            {
                grafic.Series["Puncte poligon"].Points.AddXY(x, y);
                poligon.AddPoint(new PointF((float)x, (float)y));
            }
        }

        private void grafic_MouseMove(object sender, MouseEventArgs e)
        {
            double x = 0;
            double y = 0;
            try
            {
                x = grafic.ChartAreas[0].AxisX.PixelPositionToValue(e.X);
                y = grafic.ChartAreas[0].AxisY.PixelPositionToValue(e.Y);
            }
            catch (InvalidOperationException ex)
            {

            }
            catch (ArgumentException ex)
            {

            }

            xLabel.Text = Math.Round(x, 2).ToString();
            yLabel.Text = Math.Round(y, 2).ToString();
        }

        private void generateBtn_Click(object sender, EventArgs e)
        {
            

            grafic.Series["Acoperire convexa"].Points.Clear();

            acoperireConvexa = poligon.GenerateHull();
           // MessageBox.Show(acoperireConvexa.GetNumberOfPoints().ToString());
            for (int i = 0; i < acoperireConvexa.GetNumberOfPoints(); ++i)
            {
                double x = acoperireConvexa.GetPointAt(i).X;
                
                double y = acoperireConvexa.GetPointAt(i).Y;

                
                grafic.Series["Acoperire convexa"].Points.AddXY(x, y);
                grafic.Series["Puncte acoperire convexa"].Points.AddXY(x, y);
                
            }

            grafic.Series["Acoperire convexa"].Points.AddXY(acoperireConvexa.GetPointAt(0).X, acoperireConvexa.GetPointAt(0).Y);
        }

        private void grafic_Click(object sender, EventArgs e)
        {

        }

        private void removeBtn_Click(object sender, EventArgs e)
        {
            poligon.RemovePoint();

            try
            {
                grafic.Series["Puncte poligon"].Points.RemoveAt(poligon.GetNumberOfPoints());

                if (grafic.Series["Puncte poligon"].Points.Count == 0)
                {
                    grafic.Series["Puncte poligon"].Points.AddXY(0, 0);
                    numberOfClicks = 0;
                }
            }
            catch (ArgumentOutOfRangeException ex)
            {

            }
        }

        private void button1_Click(object sender, EventArgs e)
        {
            grafic.Series["Puncte poligon"].Points.Clear();
            grafic.Series["Puncte acoperire convexa"].Points.Clear();
            grafic.Series["Acoperire convexa"].Points.Clear();

            grafic.Series["Puncte poligon"].Points.AddXY(0, 0);
            grafic.Series["Puncte poligon"].Points[0].Color = Color.Transparent;
            numberOfClicks = 0;

            int n = poligon.GetNumberOfPoints();
            for (int i = 0; i <= n; ++i)
            {
                poligon.RemovePoint();
            }

            n = acoperireConvexa.GetNumberOfPoints();
            for (int i = 0; i < n; ++i)
            {
                acoperireConvexa.RemovePoint();
            }
        }
        
    }
}
