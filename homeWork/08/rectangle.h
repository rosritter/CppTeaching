#include <stdexcept>

class Rectangle
{
int Length;
int Breadth;
public:
    Rectangle(const int a, const int b) : Length(a), Breadth(b) {}
    int Area()
    {
        return Length * Breadth;
    }
    // отношение длинны к ширине
    double RelationsOfTheParties()
    {
        double rel = Length / Breadth;
        if (Breadth == 0) {
            throw std::runtime_error("zero division");
        }
        return rel;
    }
};

int CalculateRectArea(int l, int b)
{
    Rectangle p(l,b);
    int area = p.Area();
    return area;
}

double CalculateRectRelationsOfTheParties(int l, int b)
{
    Rectangle p(l, b);
    double relation = p.RelationsOfTheParties();
    return relation;
}
