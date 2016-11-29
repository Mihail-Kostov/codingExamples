ALTER_TRANS BOTSMITH BEGIN 4 9 15 19 23 27 31 35 39 43 47 51 55 59 63 67 72 76 82 86 89 92 96 100 102 END BEGIN 10 END // filename, state, trans
  BEGIN TRIGGER ~OR(3) PartyHasItem("clck02") PartyHasItem("cdpp9") PartyHasItem("c!pp9")~ END

ADD_TRANS_TRIGGER BOTSMITH 108 ~!PartyHasItem("cdpp9") !PartyHasItem("c!pp9")~ DO 1

EXTEND_BOTTOM BOTSMITH 108
  IF ~PartyGoldGT(19999)
      PartyHasItem("cdpp9") 
      !PartyHasItem("c!pp9")~ THEN REPLY #66939 DO ~SetGlobal("ItemMaker","GLOBAL",28)
                                                    TakePartyGold(20000)
                                                    TakePartyItemNum("cdpp9",1) // Cloak of Protection +2
                                                    DestroyItem("cdpp9") // Cloak of Protection +2
                                                    TakePartyItemNum("scrl90",1) // Invisibility
                                                    DestroyItem("scrl90") // Invisibility
                                                    TakePartyItemNum("scrl7q",1) // Improved Haste
                                                    DestroyItem("scrl7q") // Improved Haste
                                                    DestroyGold(20000)~ GOTO 11
  IF ~PartyGoldGT(19999)
      PartyHasItem("c!pp9")~ THEN REPLY #66939 DO ~SetGlobal("ItemMaker","GLOBAL",28)
                                                    TakePartyGold(20000)
                                                    TakePartyItemNum("c!pp9",1) // Cloak of Protection +2
                                                    DestroyItem("c!pp9") // Cloak of Protection +2
                                                    TakePartyItemNum("scrl90",1) // Invisibility
                                                    DestroyItem("scrl90") // Invisibility
                                                    TakePartyItemNum("scrl7q",1) // Improved Haste
                                                    DestroyItem("scrl7q") // Improved Haste
                                                    DestroyGold(20000)~ GOTO 11
END