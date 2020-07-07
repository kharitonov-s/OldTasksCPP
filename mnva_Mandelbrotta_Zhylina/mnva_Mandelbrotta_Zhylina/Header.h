// Рисуем фрактал Мандельброта
/*#include <GL/glut.h>
#include <cmath>
#include <complex>

typedef std::complex<double> Complex;

Complex sqr(const Complex &v)
{
	return pow(v, 2);
}

void display()
{
	QCustomPlot* customPlot = ui->plot;
	QVector<double> x(101), y(101), y1(101);
	int i = 0;
	Complex z(0, 0);
	for (int y2 = 0; y2 < 101; ++y2)
		for (int x1 = 0; x1 < 101; ++x1)
		{

			while (i < 1000 && abs(z) < 2)
			{
				z = sqr(z) + Complex(1.0 * (x1 - 100) / 70,
					1.0 * (y2 - 100) / 70);
				++i;
			}
			//Добавление графика
			customPlot->addGraph();
			customPlot->graph(0)->setData(x, y);
			//customPlot->xAxis->setRange(-1,1);
			//customPlot->yAxis->setRange(0,1);
			customPlot->graph(0)->rescaleAxes();

			customPlot->addGraph();
			customPlot->graph(1)->setPen(QPen(Qt::red));
			customPlot->graph(1)->setData(x, y1);

			customPlot->setInteractions(QCP::iRangeDrag |
				QCP::iRangeZoom |
				QCP::iSelectPlottables);
		}
}
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(200, 200);
	glutInitWindowPosition(20, 810);
	glutCreateWindow("Mandelbrot");
	glClearColor(0, 0, 0, 1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, 200, 200, 0, -1, 1);
	glutDisplayFunc(display);
	glutMainLoop();
}*/

class Pixel
{
	float r, g, b;

};