 # Informação e Codificação - Proj1


 Departamento de Electrónica, Telecomunicações e Informática - Universidade de Aveiro

 ---

## [Pré-requisitos -> instructions](instructions)

## [Compilação dos exercícios](README.md)


- Comandos gerais:
```c++
bin/class <all_arguments>       # executar class

make                            # compilar todos os programas para execução

make clean                      # limpar programas de execução

```
---
- Exercício 2:
```c++
./sndfile-example-bin/wav_hist ../sample01.wav 0            # canal esquerdo
                                               1            # canal direito
                                               -mid         # canal MID
                                               -side        # canal SIDE

```
---

- Exercício 3:
```c++
./sndfile-example-bin/wav_quant ../sample.wav 0 quantized_sample.wav

criar histograma: ./sndfile-example-bin/wav_hist quantized_sample 0 >> quantized_sample.txt

```
---

- Exercício 4:

```c++
No diretório sndfile-example-src:
../sndfile-example-bin/wav_quant sample.wav 0 quantized-sample.wav  # criar ficheiro quantizado
../sndfile-example-bin/wav_cmp sample.wav quantized-sample.wav      # comparar ficheiro original com o ficheiro quantizado
```
---

- Exercício 5:

```c++
No diretório sndfile-example-src:
../sndfile-example-bin/wav_effects sample.wav left_mute.wav mute           # efeito de silenciar canal
../sndfile-example-bin/wav_effects sample.wav echo-output.wav single-echo  # efeito de single echo

```
---

- Exercício 7:
```c++
./sndfile-example-bin/encoder from.txt to.bin       #escrever de um ficheiro de texto para um ficheiro binário

./sndfile-example-bin/decoder to.txt from.bin       #ler de um ficheiro binário e armazenar num ficheiro de texto

Existem dois ficheiros, text.txt e bin.bin, que podem ser utilizados para testes.
```

---
## Equipa
| Name | Github | Email |  Contribuição(%) |
|------|--------|-------|-------|
| Diana Rocha | [rochadc00](https://github.com/rochadc00) | rochadc00@ua.pt | 25
| Claudio Asensio | [ClaudioAsensio](https://github.com/ClaudioAsensio) | claudioasensio@ua.pt | 37.5
| Hugo Domingos | [Hugo-Domingos](https://github.com/Hugo-Domingos) | hugodomingos@ua.pt | 37.5
