:: Generates documentation using doxyxgen (https://www.doxygen.nl/) for all projects
@ECHO OFF
for %%s in ("tobot_core" "tobot_data_structures" "tobot_io" "tobot_lang" "tobot_math" "tobot_test" "tobot_tooling") do CALL ./docs.bat %%s
EXIT 0