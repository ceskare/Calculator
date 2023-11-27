#ifndef CPP3_SMARTCALC_V2_0_TESTS_TESTS_H_
#define CPP3_SMARTCALC_V2_0_TESTS_TESTS_H_

static const double kAccuracy = 10e-6;

static char kTestCalculation[10][200] = {"1+1",
                                         "12/1*5/51+17-124/21*90*(12+2)",
                                         "-15+12+1+(1+1)",
                                         "1",
                                         "1234^2",
                                         "14mod3",
                                         "14+5/12*31-84+12mod4",
                                         "10000000000000/100000000000",
                                         "1234*1234-(1234*4321)+4321*1234",
                                         "-123"};

static double kCalculationResult[10] = {
    2.000000, -7421.823529, 0.000000, 1.000000, 1522756.000000,
    2.000000, -57.083333,   100,      1522756,  -123};

static char kTestFunction[10][200] = {
    "sin(sin(sin(1)))",    "cos(cos(cos(1)))",
    "tan(tan(tan(1)))",    "asin(asin(asin(0)))",
    "acos(acos(1))",       "atan(atan(atan(1)))",
    "log(log(log(100)))",  "ln(ln(ln(10)))",
    "sqrt(sqrt(sqrt(1)))", "sin(cos(tan(atan(log(ln(sqrt(1)))))))"};

static double kFunctionResult[10] = {0.678430, 0.654289, -0.863518, 0.000000,
                                     1.570796, 0.587384, -0.521390, -0.181483,
                                     1,        -0.280611};

static char kTestCalcError[10][200] = {
    "-1^1.2",   "-21^(-1.2)",
    "asin(5)",  "asin(-5)",
    "acos(5)",  "acos(-5)",
    "log(-5)",  "ln(-5)",
    "sqrt(-5)", "asin(acos(log(ln(sqrt(-5)))))"};

static char kTestError[10][200] = {
    "(-1^1.2", "-21^-1.2)", "/21^(*21*21)", "sin()",    "mod",
    "cos()",   "/acos(5)",  "(acos(-5)",    "log(-5))", "(ln(-5)"};

#endif  // CPP3_SMARTCALC_V2_0_TESTS_TESTS_H_
