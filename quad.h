static const int INF_ROOTS = -1; //возвращаемое значение solve_equation, если корней бесконечно много
static const double EPS_COEF = 1e-7; //точность определения нулевых коэффициентов

int solve_equation(double a, double b, double c, int root_sign_count, double *x1, double *x2);//функция, которая решает уравнение и возвращает количество корней
int cmpdoubles(double a, double b, double eps);//функция для сравнения даблов с заданной точностью

