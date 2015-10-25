namespace totalLibrary.MathCalc
{
    public class SolvingFormula
    {
        public static string Sformulaplus(float a, float b, float c)
        {
            double radical;
            double calc;
            radical = System.Math.Sqrt(b*b - 4*a*c);
            calc = (-b + radical)/2*a;
            if (radical < 0)
            {
                return "IMPOSSIBLE!";
            }
            else
            {
                string calcstr;
                calcstr = calc.ToString();
                return calcstr;
            }    
        }
        public static string Sformulaless(float a, float b, float c)
        {
            double radical;
            double calc;
            radical = System.Math.Sqrt(b * b - 4 * a * c);
            calc = (-b - radical) / 2 * a;
            if (radical < 0)
            {
                return "IMPOSSIBLE!";
            }
            else
            {
                string calcstr;
                calcstr = calc.ToString();
                return calcstr;
            }
        }
    }
}
