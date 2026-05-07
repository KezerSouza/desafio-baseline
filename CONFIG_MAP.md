# CONFIG_MAP.md — Mapa de Itens de Configuração

## Itens de Configuração (ICs)

| ID   | Nome                    | Tipo              | Versão  | Descrição                                              |
|------|-------------------------|-------------------|---------|--------------------------------------------------------|
| IC01 | somador                 | Código-fonte      | 1.0.0   | Programa principal em C (`src/main.c`)                 |
| IC02 | gcc                     | Compilador        | ≥ 9.0.0 | Compilador C utilizado para gerar o binário            |
| IC03 | .env                    | Configuração      | 1.0.0   | Arquivo de variáveis de ambiente do projeto            |
| IC04 | README.md               | Documentação      | 1.0.0   | Documentação de uso e requisitos do projeto            |
| IC05 | CONFIG_MAP.md           | Documentação      | 1.0.0   | Este arquivo — mapa de ICs e política de versões       |
| IC06 | Linux (bash)            | Ambiente/SO       | ≥ 5.0   | Sistema operacional e shell exigidos para execução     |
| IC07 | Git                     | Ferramenta SCM    | ≥ 2.0.0 | Controle de versão do repositório                      |

---

## Política de Nomenclatura de Versões

O projeto adota **Versionamento Semântico (SemVer)** no formato:

```
MAJOR.MINOR.PATCH
```

| Campo   | Quando incrementar                                                                 |
|---------|------------------------------------------------------------------------------------|
| MAJOR   | Mudança incompatível com versões anteriores (ex: alteração de interface, remoção de funcionalidade) |
| MINOR   | Nova funcionalidade adicionada de forma retrocompatível                            |
| PATCH   | Correção de bug ou ajuste sem impacto em funcionalidades                           |

### Exemplos

| Versão  | Situação                                                        |
|---------|-----------------------------------------------------------------|
| `1.0.0` | Versão inicial estável — baseline do projeto                    |
| `1.0.1` | Correção de bug na leitura do `.env`                            |
| `1.1.0` | Suporte a operações além da soma (média, por exemplo)           |
| `2.0.0` | Reescrita do programa com interface diferente                   |

### Tags Git

Cada baseline é marcada com uma tag Git no formato `vMAJOR.MINOR.PATCH`:

```bash
git tag -a v1.0.0 -m "Baseline inicial do projeto Somador"
```
