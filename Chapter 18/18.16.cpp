//Exercise 18.16: Explain the following code assuming using declarations for
//all the members of namespace Exercise are located at the location labeled
//position 1. What if they appear at position 2 instead? Now answer the same
//question but replace the using declarations with a using directive for
//namespace Exercise.
//
//namespace Exercise {
//int ivar = 0;
//double dvar = 0;
//const int limit = 1000;
//}
//int ivar = 0;
//// position 1
//void manip() {
//// position 2
//double dvar = 3.1416;
//int iobj = limit + 1;
//++ivar;
//++::ivar;
//}
//Answer:
//using Exercise::dvar and using Exercise::limit would work properly however Exercise::ivar will cause redefinition
//of the local ivar that was declared above it and the program will not compile, in addition, ++ivar and ++::ivar will refer to the
//same local ivar.
//If the using declarations would appear at position 2, using Exercise::ivar and using Exercise::limit would work however
//using Exercise::dvar will cause a compilation error, in addition, ++ivar will increase Exercise::ivar and ++::ivar will
//increase the outer ivar and the limit of Exercise will be used.
//
//using directives, for position 1, limit will direct to Exercise::limit, however ++ivar will cause ambiguity since both
//Exercise::ivar and the outer ivar are in scope, and ++::ivar will refer to the outer ivar.
//using directive, for position 2, Exercise::limit will be used however ++ivar will cause ambiguity since both
//Exercise::ivar and the outer ivar are in scope and ++::ivar will refer to the outer ivar.
//
//Exercise 18.17: Write code to test your answers to the previous question.
namespace DeclarationPos1
{
    namespace Exercise {
        int ivar = 0;
        double dvar = 0;
        const int limit = 1000;
    }
    int ivar = 0;
// position 1
//using Exercise::ivar; -->redefinition
using Exercise::dvar;
using Exercise::limit;
    void manip() {
        double dvar = 3.1416;
        int iobj = limit + 1;
        ++ivar;
        ++DeclarationPos1::ivar;
    }
}

namespace DeclarationPos2
{
    namespace Exercise {
        int ivar = 0;
        double dvar = 0;
        const int limit = 1000;
    }
    int ivar = 0;
    void manip() {
        using Exercise::ivar;
        using Exercise::limit;
        double dvar = 3.1416;
        int iobj = limit + 1;
        ++ivar;
        ++DeclarationPos2::ivar;
    }
}
namespace DirectivePos1
{
    namespace Exercise {
        int ivar = 0;
        double dvar = 0;
        const int limit = 1000;
    }
    int ivar = 0;
// position 1
    using namespace Exercise;
    void manip() {
        double dvar = 3.1416;
        int iobj = limit + 1;
        //++ivar; ---> ambiguous
        ++DirectivePos1::ivar;
    }
}

namespace DirectivePos2
{
    namespace Exercise {
        int ivar = 0;
        double dvar = 0;
        const int limit = 1000;
    }
    int ivar = 0;
    void manip() {
        using namespace Exercise;
        double dvar = 3.1416;
        int iobj = limit + 1;
        //++ivar; ---> ambiguous
        ++DirectivePos2::ivar;
    }
}
class CAD{};
class Vehicle{};
class CADVehicle : public CAD, Vehicle { };
int main()
{
    DeclarationPos1::manip();
    DeclarationPos2::manip();
    DirectivePos1::manip();
    DirectivePos2::manip();
    return 0;
}