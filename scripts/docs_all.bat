:: Generates documentation using doxyxgen (https://www.doxygen.nl/)
@ECHO OFF
for %%s in ("tobot_core" "tobot_math" "tobot_tooling") do CALL ./docs.bat %%s