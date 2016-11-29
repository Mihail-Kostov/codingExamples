EXTEND_TOP FATESP 6 #18
  IF ~!Dead("Viconia")
      !InMyArea("Viconia")
      Global("ViconiaSummoned","GLOBAL",0)
      Global("FWViconiaSummonedInRomance","GLOBAL",0)~ THEN REPLY @318317 DO ~SetGlobal("ViconiaRomanceActive","GLOBAL",2)
                                                                              SetGlobal("ViconiaSummoned","GLOBAL",1)
                                                                              SetGlobal("FWViconiaSummonedInRomance","GLOBAL",1)~ GOTO 8
END

EXTEND_TOP FATESP 6 #16 // rasaad
  IF ~HasDLC("Rasaad")
      !Dead("RASAAD")
      !InMyArea("RASAAD")
      Global("OHR_RasaadSummoned","GLOBAL",0)
      Global("CDRasaadSummonedInRomance","GLOBAL",0)~ THEN REPLY @318321 DO ~SetGlobal("RasaadRomanceActive","GLOBAL",2)
                                                                             SetGlobal("OHR_RasaadSummoned","GLOBAL",1)
                                                                             SetGlobal("CDRasaadSummonedInRomance","GLOBAL",1)~ GOTO 8
END

EXTEND_TOP FATESP 6 #14 // neera
  IF ~HasDLC("Neera")
      !Dead("Neera")
      !InMyArea("Neera")
      Global("OHN_NeeraSummoned","GLOBAL",0)
      Global("CDNeeraSummonedInRomance","GLOBAL",0)~ THEN REPLY @318320 DO ~SetGlobal("NeeraRomanceActive","GLOBAL",2)
                                                                            SetGlobal("OHN_NeeraSummoned","GLOBAL",1)
                                                                            SetGlobal("CDNeeraSummonedInRomance","GLOBAL",1)~ GOTO 8
END

EXTEND_TOP FATESP 6 #8
  IF ~!Dead("Jaheira")
      !InMyArea("Jaheira")
      Global("JaheiraSummoned","GLOBAL",0)
      Global("FWJaheiraSummonedInRomance","GLOBAL",0)~ THEN REPLY @318314 DO ~SetGlobal("JaheiraRomanceActive","GLOBAL",2)
                                                                              SetGlobal("JaheiraSummoned","GLOBAL",1)
                                                                              SetGlobal("FWJaheiraSummonedInRomance","GLOBAL",1)~ GOTO 8
END

EXTEND_TOP FATESP 6 #6 // hexxat
  IF ~HasDLC("hexxat")
      !Dead("hexxat")
      !InMyArea("hexxat")
      Global("OHH_HexxatSummoned","GLOBAL",0)
      Global("CDHexxatSummonedInRomance","GLOBAL",0)~ THEN REPLY @318319 DO ~SetGlobal("HexxatRomanceActive","GLOBAL",2)
                                                                             SetGlobal("OHH_HexxatSummoned","GLOBAL",1)
                                                                             SetGlobal("CDHexxatSummonedInRomance","GLOBAL",1)~ GOTO 8
END

EXTEND_TOP FATESP 6 #3 // dorn
  IF ~HasDLC("Dorn")
      !Dead("Dorn")
      !InMyArea("Dorn")
      Global("OHD_DornSummoned","GLOBAL",0)
      Global("CDDornSummonedInRomance","GLOBAL",0)~ THEN REPLY @318318 DO ~SetGlobal("DornRomanceActive","GLOBAL",2)
                                                                           SetGlobal("OHD_DornSummoned","GLOBAL",1)
                                                                           SetGlobal("CDDornSummonedInRomance","GLOBAL",1)~ GOTO 8
END

EXTEND_TOP FATESP 6 #1
  IF ~!Dead("Anomen")
      !InMyArea("Anomen")
      Global("AnomenSummoned","GLOBAL",0)
      !Dead("Saerk")
      Global("FWLGAnomenSummonedInRomance","GLOBAL",0)~ THEN REPLY @318315 DO ~SetGlobal("AnomenRomanceActive","GLOBAL",2)
                                                                               SetGlobal("AnomenSummoned","GLOBAL",1)
                                                                               SetGlobal("FWLGAnomenSummonedInRomance","GLOBAL",1)
                                                                               SetGlobal("AnomenIsKnight","GLOBAL",1)~ GOTO 8
  IF ~!Dead("Anomen")
      !InMyArea("Anomen")
      Global("AnomenSummoned","GLOBAL",0)
      Global("FWCNAnomenSummonedInRomance","GLOBAL",0)~ THEN REPLY @318316 DO ~SetGlobal("AnomenRomanceActive","GLOBAL",2)
                                                                               SetGlobal("AnomenSummoned","GLOBAL",1)
                                                                               SetGlobal("FWCNAnomenSummonedInRomance","GLOBAL",1)
                                                                               SetGlobal("AnomenIsNotKnight","GLOBAL",1)~ GOTO 8

END

EXTEND_TOP FATESP 6
  IF ~!Dead("Aerie")
      !InMyArea("Aerie")
      Global("AerieSummoned","GLOBAL",0)
      Global("FWAerieSummonedInRomance","GLOBAL",0)~ THEN REPLY @318313 DO ~SetGlobal("AerieRomanceActive","GLOBAL",2)
                                                                            SetGlobal("AerieSummoned","GLOBAL",1)
                                                                            SetGlobal("FWAerieSummonedInRomance","GLOBAL",1)~ GOTO 8
END