#include "projeto.h"
#include <stdio.h>

int main() {
  int op;
  do {

    op = menu();

    if (op == 1) {
      cadastroDisciplina();
    }
    if (op == 2) {
      cadastroAluno();
    }

    if (op == 3) {
      apagaAluno();
    }

    if (op == 4) {
      cadastroNotas();
    }

    if (op == 5) {
      gerar_relatorio();
    }

  } while (op != 0);
}
