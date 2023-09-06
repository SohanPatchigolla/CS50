#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>

int pay_f(int hours, int base_pay_dollars, const int normal_hours, int overtime_pay_dollars, int pay);
int taxes_f(int g_pay, float slab_1st, float slab_2nd, float slab_3rd, int slab_1st_limit, int slab_2nd_limit, int tax);

int main(void)
{
    const int normal_hours = get_int("Enter total number of normal working hours per week: "); // normal hours

    int hours = get_int("Enter Hours Worked: "); // takes hours as input

    int base_pay_dollars = get_int("Enter Base Pay in dollars: "); // takes base pay as input

    float overtime_payrate = 1.5; // overtime payrate in percent.

    int overtime_pay_dollars = (base_pay_dollars * overtime_payrate); // calculates overtime payrate in dollars.

    int ini_pay = 0; // should write zero, but using it convinece sake.

    int gross_pay = pay_f(hours, base_pay_dollars, normal_hours, overtime_pay_dollars, ini_pay);

    printf("gross_pay: %i\n", gross_pay);

    int ini_tax = 0.0;

    int net_pay = taxes_f(gross_pay, 15, 20, 25, 300, 150, ini_tax);

    printf("net_pay: %i\n", net_pay);

}

int pay_f(int hours, int base_pay_dollars, const int normal_hours, int overtime_pay_dollars, int pay)
{
    if (hours <= normal_hours)
    {
        pay = hours * base_pay_dollars;
    }
    else if (hours > normal_hours)
    {
        int normal_pay = normal_hours* base_pay_dollars; // calculates normal pay
        int overtime_hours = hours - normal_hours; // overtime hours
        int overtime_pay = overtime_hours * overtime_pay_dollars; // calculates overtime pay
        pay = normal_pay + overtime_pay; // total pay
    }

    return pay;
}

int taxes_f(int g_pay, float slab_1st, float slab_2nd, float slab_3rd, int slab_1st_limit, int slab_2nd_limit, int tax)
{
    int p = 100;
    const int slab_const_1st = (300 * (slab_1st / p));
    const int slab_const_2nd = (150 * (slab_2nd / p));

    if (g_pay <= 300)
    {
        tax = g_pay * (slab_1st / p);
    }
    else if (g_pay <= 450)
    {
        int rest_pay = g_pay - 300;
        int slab_tax_2nd = rest_pay * (slab_2nd / p);
        tax = slab_const_1st + slab_tax_2nd;
    }
    else if (g_pay > 450)
    {
        int rest_pay = g_pay - 450;
        int slab_tax_3rd = rest_pay * (slab_3rd / p);
        tax = slab_const_1st + slab_const_2nd + slab_tax_3rd;
    }

    int n_pay = g_pay - tax;

    return n_pay;
}