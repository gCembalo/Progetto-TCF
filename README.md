# Progetto-TCF
Progetto di Battaglia navale di "Tecniche di Calcolo per la Fisica"

Di:
1) Giulia Brancaccio
2) Gabriele Cembalo
3) Emmanuel Cuonzo
4) Laura Dellana

## Tecniche di Calcolo per la Fisica: Istruzioni per l’Esame
Scegliere uno dei temi d’esame proposti e svolgerlo in un gruppo di 2-4 persone.
Per svolgere un tema d’esame occorre:
- disegnare lo User Case Diagram ed il Class Diagram
- scrivere il codice corrispondente e verificare che compili ed esegua correttamente

Completato il tema d’esame, si concorda un appuntamento con il docente per commentare e
discutere il tema d’esame svolto e ricevere il voto.
Il voto sarà registrato al primo appello ufficiale dopo la discussione del tema d’esame.

## Tema d’esame: Battaglia Navale

Sviluppare un programma per giocare a battaglia navale per due giocatori. Ogni giocatore ha una flotta di un certo numero di navi. Ogni nave occupa un certo numero di caselle su una “scacchiera “. Ogni casella della scacchiera è individuata da 2 numeri interi. All’inizio della partita i due giocatori dispongono le loro flotte sulla scacchiera in segreto. In ogni turno, entrambi i giocatori scelgono una casella in cui sparare ed il computer verifica se il colpo è finito in mare oppure ha colpito una nave dell’avversario. Una nave è affondata quando tutte le caselle che occupa sono state colpite. Vince il giocatore che per primo affonda tutte le navi dell’avversario. Sviluppare due versioni del gioco: umano contro umano ed umano contro computer. La versione umano contro computer richiede lo sviluppo di una semplice intelligenza artificiale che:
- sceglie in modo casuale le caselle su cui sparare
- se colpisce una nave, spara nelle caselle adiacenti fino a quando non la affonda e poi
riprende a scegliere in modo casuale la casella in cui sparare...
