# TODO

# EX01
- 電話帳のvalidateなどは、iphoneの電話帳などを参考にする。
- 内部indexと外部indexを紐付ける関数を作る。f: {1~8}->{0~7}
- EOFで正常に終了するようにする。
- PhoneBook> a、のときにEOF１回押しても終わらなくて、２回押さないと終了しない。
- launch()終わったら中身のデータを消去する。
- std::cin.clear(), std::cin.fail(), std::cin.ignore(),を使いこなせるようにする。
- 

# EX02
- `[19920104_091532]`: _displayTimestamp()
- `accounts:8;total:12442;deposits:8;withdrawals:6`: displayAccountsInfos()
- `index:0;amount:47;deposits:1;withdrawals:0`: displayStatus()
- `index:0;p_amount:42;deposit:5;amount:47;nb_deposits:1`: makeDeposit()
- `index:1;p_amount:819;withdrawal:34;amount:785;nb_withdrawals:1`: makeWithdrawal()
- vector, pair, iterator, など、このプログラムで使用されている構文などを使いこなせるようにする。
- class内のstatic関数は、Account::getNbAccounts()のように、クラス実態を作らなくとも使用できる。