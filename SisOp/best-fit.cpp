// best fit implementacao - william spader
#include <iostream>
#include <vector>

typedef std::vector<int> vi;

void bestFit(vi & lacunas, vi & processos);

int main(void)
{
	vi lacunas, processos;
	//vi::iterator it;
	short qtd;
	short i = 0;
	
	printf("\n Digite zero ou um numero negativo para sair da entrada de lacunas\n");
	printf("\n Digite uma quantidade para lacuna %d: ", i);
	while (std::cin >> qtd)
	{
		if (qtd <= 0) break;
		lacunas.push_back(qtd);
		i++;
		printf("\n Digite uma quantidade para lacuna %d: ", i);
	}
	i = 0;
	printf("\n --- Voce saiu da entrada de lacunas ---\n");
	
	printf("\n Digite zero ou um numero negativo para sair da entrada de processos\n");
	printf("\n Digite uma quantidade para o processo %d: ", i);
	
	while (std::cin >> qtd)
	{
		if (qtd <= 0) break;
		processos.push_back(qtd);
		i++;
		printf("\n Digite uma quantidade para o processo %d: ", i);
	}
	
	bestFit(lacunas, processos);
	
	//for (it = lacunas.begin(); it != lacunas.end(); ++it) std::cout << *it << std::endl;
	//for (it = processos.begin(); it != processos.end(); ++it) std::cout << *it << std::endl;
	std::cout << "\n--- Versao final da memoria apos alocacao dos processos ---\n\n";
	vi::size_type n = lacunas.size();
	for (i = 0; i < n; i++)
	{
		if (i == (n - 1)) std::cout << lacunas[i] << "K";
		else std::cout << lacunas[i] << "K, ";
	}
	std::cout << std::endl;
	
	return 0;
}

/*
 * Algoritmo guloso
 * Nao achei interessante ordenar
 * Analise assintotica:
 * --- n = quantidade de lacunas
 * --- m = quantidade de processos
 * --- O(n*m)
*/
void bestFit(vi & lacunas, vi & processos)
{
	short i, j, idx;
	for (i = 0; i < processos.size(); i++)
	{
		idx = -1;
		for (j = 0; j < lacunas.size(); j++)
		{
			if (lacunas[j] >= processos[i])
			{
				if (idx == -1) idx = j; // guarda o indice pela primeira vez
				else if (lacunas[idx] > lacunas[j]) idx = j; // se existe uma lacuna maior que o processo mas menor que o indice guardado
			}
		}
		if (idx == -1) std::cout << "Nao foi possivel alocar o processo " << i << " de " << processos[i] << "K" << std::endl;
		else lacunas[idx] -= processos[i]; // diminui o espaco que sera utilizado pelo processo
	}
}
