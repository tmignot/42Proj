%module threadlaunch
%{
  extern int launch(void);
  extern void stop(void);
%}

extern int launch(void);
extern void stop(void);
