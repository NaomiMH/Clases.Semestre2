#ifndef RELOJ_H
#define RELOJ_H


class Reloj
{
    public:
        Reloj();
        void setTime(int, int, int);
        void getTime(int&,int&,int&) const;
        void printTime() const;
        void incrementSeconds();
        void incrementMinutes();
        void incrementHours();
        bool equalTime(const Reloj&) const;
    private:
        int hr;
        int minutos;
        int sec;
};

#endif // RELOJ_H
