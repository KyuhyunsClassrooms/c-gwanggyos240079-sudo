#include <stdio.h>

#define Q 1.6e-19  // 전자 전하량 (C)

// 이동도 값 (상온 기준 단순 모델)
#define MU_N 1350   // n형 이동도 (cm^2/Vs)
#define MU_P 450    // p형 이동도 (cm^2/Vs)

int main() {
    double doping;    // 도핑 농도 (cm^-3)
    char type;        // n 또는 p
    double mu;        // 이동도
    double sigma;     // 전기전도도 (S/cm)

    printf("도핑 타입 입력 (n 또는 p): ");
    scanf(" %c", &type);

    printf("도핑 농도 N (예: 1e16 ) 입력 (cm^-3): ");         
    scanf("%lf", &doping);

    // 이동도 선택
    if (type == 'n' || type == 'N') {
        mu = MU_N;
    } else if (type == 'p' || type == 'P') {
        mu = MU_P;
    } else {
        printf("잘못된 타입 입력\n");
        return 1;
    }

    // 전기전도도 계산
    sigma = Q * mu * doping;

    printf("\n=== 계산 결과 ===\n");
    printf("도핑 타입: %c형\n", type);
    printf("도핑 농도 N: %.3e cm^-3\n", doping);
    printf("이동도 μ: %.1f cm^2/Vs\n", mu);
    printf("전기전도도 σ: %.3e S/cm\n", sigma);

    return 0;
}