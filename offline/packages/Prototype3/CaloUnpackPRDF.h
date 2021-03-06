// Tell emacs that this is a C++ source
//  -*- C++ -*-.
#ifndef PROTOTYPE3_CALOUNPACKPRDF_H
#define PROTOTYPE3_CALOUNPACKPRDF_H

//* Unpacks raw HCAL PRDF files *//
// Abhisek Sen

#include <fun4all/SubsysReco.h>

class Event;
class Packet_hbd_fpgashort;
class PHCompositeNode;
class RawTowerContainer;

class CaloUnpackPRDF : public SubsysReco
{
 public:
  CaloUnpackPRDF();

  int InitRun(PHCompositeNode *topNode);

  int process_event(PHCompositeNode *topNode);

  void CreateNodeTree(PHCompositeNode *topNode);

  //! whether to use high eta EMCal
  void set_use_high_eta_EMCal(bool b) { _use_high_eta_EMCal = b ? 1 : 0; }

 private:
  Event *_event;
  Packet_hbd_fpgashort *_packet;
  int _nevents;

  //! -1 - read from RunInfo, +1, true, 0 false;
  int _use_high_eta_EMCal;

  // HCAL node
  PHCompositeNode *dst_node;
  PHCompositeNode *data_node;

  // Towers
  RawTowerContainer *hcalin_towers_lg;
  RawTowerContainer *hcalout_towers_lg;

  RawTowerContainer *hcalin_towers_hg;
  RawTowerContainer *hcalout_towers_hg;

  RawTowerContainer *emcal_towers;
};

#endif
