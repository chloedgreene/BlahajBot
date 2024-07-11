{ pkgs, ... }:

{


  packages = [ pkgs.gcc-arm-embedded ];

  languages.python = {
    enable = true;
    version = "3.11.8";

    venv.enable = true;
    venv.requirements = ./requirements.txt;
  };

  # https://devenv.sh/services/
  # services.postgres.enable = true;

  # https://devenv.sh/languages/
  # languages.nix.enable = true;

  # https://devenv.sh/pre-commit-hooks/
  # pre-commit.hooks.shellcheck.enable = true;

  # https://devenv.sh/processes/
  # processes.ping.exec = "ping example.com";

  # See full reference at https://devenv.sh/reference/options/
}
