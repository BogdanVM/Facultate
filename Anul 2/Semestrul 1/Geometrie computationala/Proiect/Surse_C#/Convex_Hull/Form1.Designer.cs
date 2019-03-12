namespace WindowsFormsApp1
{
    partial class Form1
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            System.Windows.Forms.DataVisualization.Charting.ChartArea chartArea5 = new System.Windows.Forms.DataVisualization.Charting.ChartArea();
            System.Windows.Forms.DataVisualization.Charting.Legend legend5 = new System.Windows.Forms.DataVisualization.Charting.Legend();
            this.grafic = new System.Windows.Forms.DataVisualization.Charting.Chart();
            this.removeBtn = new System.Windows.Forms.Button();
            this.generateBtn = new System.Windows.Forms.Button();
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.xLabel = new System.Windows.Forms.Label();
            this.yLabel = new System.Windows.Forms.Label();
            this.button1 = new System.Windows.Forms.Button();
            ((System.ComponentModel.ISupportInitialize)(this.grafic)).BeginInit();
            this.SuspendLayout();
            // 
            // grafic
            // 
            chartArea5.Name = "ChartArea1";
            this.grafic.ChartAreas.Add(chartArea5);
            this.grafic.Dock = System.Windows.Forms.DockStyle.Left;
            legend5.Name = "Legend1";
            this.grafic.Legends.Add(legend5);
            this.grafic.Location = new System.Drawing.Point(0, 0);
            this.grafic.Name = "grafic";
            this.grafic.Size = new System.Drawing.Size(566, 320);
            this.grafic.TabIndex = 0;
            this.grafic.Text = "chart1";
            this.grafic.Click += new System.EventHandler(this.grafic_Click);
            this.grafic.MouseClick += new System.Windows.Forms.MouseEventHandler(this.grafic_MouseClick);
            this.grafic.MouseMove += new System.Windows.Forms.MouseEventHandler(this.grafic_MouseMove);
            // 
            // removeBtn
            // 
            this.removeBtn.Location = new System.Drawing.Point(602, 12);
            this.removeBtn.Name = "removeBtn";
            this.removeBtn.Size = new System.Drawing.Size(168, 44);
            this.removeBtn.TabIndex = 1;
            this.removeBtn.Text = "Remove point";
            this.removeBtn.UseVisualStyleBackColor = true;
            this.removeBtn.Click += new System.EventHandler(this.removeBtn_Click);
            // 
            // generateBtn
            // 
            this.generateBtn.Location = new System.Drawing.Point(602, 62);
            this.generateBtn.Name = "generateBtn";
            this.generateBtn.Size = new System.Drawing.Size(168, 44);
            this.generateBtn.TabIndex = 2;
            this.generateBtn.Text = "Generate convex hull";
            this.generateBtn.UseVisualStyleBackColor = true;
            this.generateBtn.Click += new System.EventHandler(this.generateBtn_Click);
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("Microsoft Sans Serif", 14.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label1.Location = new System.Drawing.Point(590, 242);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(34, 24);
            this.label1.TabIndex = 3;
            this.label1.Text = "X: ";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Font = new System.Drawing.Font("Microsoft Sans Serif", 14.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label2.Location = new System.Drawing.Point(702, 242);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(32, 24);
            this.label2.TabIndex = 4;
            this.label2.Text = "Y: ";
            // 
            // xLabel
            // 
            this.xLabel.AutoSize = true;
            this.xLabel.Font = new System.Drawing.Font("Microsoft Sans Serif", 14.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.xLabel.Location = new System.Drawing.Point(621, 242);
            this.xLabel.Name = "xLabel";
            this.xLabel.Size = new System.Drawing.Size(20, 24);
            this.xLabel.TabIndex = 5;
            this.xLabel.Text = "0";
            // 
            // yLabel
            // 
            this.yLabel.AutoSize = true;
            this.yLabel.Font = new System.Drawing.Font("Microsoft Sans Serif", 14.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.yLabel.Location = new System.Drawing.Point(735, 242);
            this.yLabel.Name = "yLabel";
            this.yLabel.Size = new System.Drawing.Size(20, 24);
            this.yLabel.TabIndex = 6;
            this.yLabel.Text = "0";
            // 
            // button1
            // 
            this.button1.Location = new System.Drawing.Point(602, 112);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(168, 44);
            this.button1.TabIndex = 7;
            this.button1.Text = "Delete all points";
            this.button1.UseVisualStyleBackColor = true;
            this.button1.Click += new System.EventHandler(this.button1_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(800, 320);
            this.Controls.Add(this.button1);
            this.Controls.Add(this.yLabel);
            this.Controls.Add(this.xLabel);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.generateBtn);
            this.Controls.Add(this.removeBtn);
            this.Controls.Add(this.grafic);
            this.Name = "Form1";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "Form1";
            this.Load += new System.EventHandler(this.Form1_Load);
            ((System.ComponentModel.ISupportInitialize)(this.grafic)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.DataVisualization.Charting.Chart grafic;
        private System.Windows.Forms.Button removeBtn;
        private System.Windows.Forms.Button generateBtn;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label xLabel;
        private System.Windows.Forms.Label yLabel;
        private System.Windows.Forms.Button button1;
    }
}

