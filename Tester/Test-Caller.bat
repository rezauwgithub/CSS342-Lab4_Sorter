@ECHO OFF
FOR /L %%A IN (1,1,50) DO (
CALL Test-All-Sort-Functions.cmd >> data.csv
ECHO %%A
)
CMD \k