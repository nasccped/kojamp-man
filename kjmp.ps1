<# ------------------------------------------------------------------
 #
 # kjmp.ps1
 #
 #    This is kjmp.ps1, the kojamp installer script for powershell
 #    based.
 #
 #    There are a simple program:
 #
 #    - you evoke the script by script name (kjmp)
 #    - give some param to reproduce a behavior
 #
 #      > install: generate binary and bytecodes
 #
 #      > rebuild: literally delete and rebuild bin/bytes
 #
 #      > reset  : delete sources (setup/ and src/) and pull it
 #                 again from github
 #
 ----------------------------------------------------------------- #>

# TODO: this entire code sucks. It's a giant beast in the shape of
#       a code. I'll definitly fix this dirty code. Don't worry ;^)

# -------------------------------------------------------------------
#
# storing variables and generators (classes)
#
# -------------------------------------------------------------------

# class to test command dependency
class Command {

  # command name and web link (case command not found)
  [string]$commandName
  [string]$webLink

  # constructor
  Command($name, $link) {
    $this.commandName = $name
    $this.webLink     = $link

    $this
  }
}

# class to test if itens are here
class Item {

  # path and error message (case item not found)
  [string]$itemPath
  [string]$errorMessage

  # constructor
  Item($path, $err) {
    $this.itemPath = $path
    $this.errorMessage = $err

    $this
  }
}

# class to store kjmp commands
class KjmpCommand {

  # store command name and description
  [string]$commandName
  [string]$commandDescription

  # constructor
  KjmpCommand($name, $desc) {
    $this.commandName = $name
    $this.commandDescription = $desc

    $this
  }
}

# getting param amount
$paramAmount = $args.Count
$programLink = "https://github.com/nasccped/kojamp-man"

# required commands
$requiredCommands = @()

# inserting requireds into array
$requiredCommands += [Command]::new("git", "https://git-scm.com/downloads")
$requiredCommands += [Command]::new("gcc", "https://gcc.gnu.org/")

# required itens
$requiredItems = @()

# inserting requireds into array
$requiredItems += [Item]::new("./setup/kojamp.c", "This file is responsible for store the program binary procedures as source code")
$requiredItems += [Item]::new("./.git", "This folder is responsible to store git data. Without it you can't pull and fetch through program versions")

# expected kjmp sub-commands
$expectedCommands = @()

# inserting sub-commands
$expectedCommands += [KjmpCommand]::new("install", "`tWill check if you have some dependencies (gcc & Java),`n`tcompile the C file to a binary and the source to an`n`t$($YEL_ESCAPE)bytecode package (*.class)$($RES_ESCAPE)")
$expectedCommands += [KjmpCommand]::new("rebuild","`tWill drop ``kojamp.exe``, ``out/`` folder and will rebuild`n`tboth. Good when binaries has unexpected behavior")
$expectedCommands += [KjmpCommand]::new("reset", "`tDrop ``kojamp.exe``, ``out/`` & ``src`` folder, and pull`n`tthem again from github remote repo. Good when we`n`thave corrupet sources")
$expectedCommands += [KjmpCommand]::new("help", "`tDisplay this current screen")

# creating colored escapes
$ESCAPE_INIT = [char]27
$RES_ESCAPE = $ESCAPE_INIT + "[0m"
$RED_ESCAPE = $ESCAPE_INIT + "[1;31m"
$GRE_ESCAPE = $ESCAPE_INIT + "[1;32m"
$YEL_ESCAPE = $ESCAPE_INIT + "[1;33m"
$BLU_ESCAPE = $ESCAPE_INIT + "[1;34m"
$WHI_ESCAPE = $ESCAPE_INIT + "[1;37m"
$UND_ESCAPE = $ESCAPE_INIT + "[4m"

# a top border / separator at terminal
$TopBorder = $WHI_ESCAPE + "`n----------------------------------------------------------------------`n" + $RES_ESCAPE
$midSep = $WHI_ESCAPE + "`n----------`n" + $RES_ESCAPE



# ----------------------------------------------------------------------
#
# behaviors as functions
#
# ----------------------------------------------------------------------

# when help/<None> is invoked
Function welcomeDisplay {

  # welcome text
  Write-Host "Welcome to $($BLU_ESCAPE)kjmp.ps1$($RES_ESCAPE), the $($BLU_ESCAPE)Kojamp setup$($RES_ESCAPE) installer!`n"

  # shows sub-commands and their descriptions
  Write-Host "Here are some possible comands:`n"

  foreach ($cmd in $expectedCommands) {

    Write-Host "  $($WHI_ESCAPE)kjmp$($RES_ESCAPE) $($YEL_ESCAPE)$($cmd.commandName):$($RES_ESCAPE)"

    Write-Host "$($cmd.commandDescription)`n"
  }

  # warning content
  Write-Host "$($RED_ESCAPE)Warning:$($RES_ESCAPE) " -NoNewline

  Write-Host "the program has a bunch of $($YEL_ESCAPE)other commands$($RES_ESCAPE) and $($YEL_ESCAPE)sub-commands$($RES_ESCAPE)"
  Write-Host "but they can be accessed by the final $($YEL_ESCAPE)binary/bytecodes output$($RES_ESCAPE). For"
  Write-Host "now, these three are all you need!`n"

  # extra info
  Write-Host "For more info, check the official github repo:"
  Write-Host "`t$($BLU_ESCAPE)$($programLink)$($RES_ESCAPE)`n"
}

# when given arguments are greater than 1
Function bigArgsAmount {

  # shows alert
  Write-Host "You have $($RED_ESCAPE)exceeded the argument limit:$($RES_ESCAPE) < $($paramAmount) >`n"

  # shows options
  Write-Host "You can try:`n"
  Write-Host "  - $($WHI_ESCAPE)kjmp$($RES_ESCAPE)"
  Write-Host "  - $($WHI_ESCAPE)kjmp$($RES_ESCAPE) $($YEL_ESCAPE)help$($RES_ESCAPE)`n"

  Write-Host "They will open the $($BLU_ESCAPE)welcome display$($RES_ESCAPE) text!`n"
}

# check if your machine have the required commands
Function checkRequiredCommands {

  # secure variable holder
  $secure = $true

  # for each element in our required commands array
  foreach ($val in $requiredCommands) {

    # if command name doesn't exists
    if (-not (Get-Command $val.commandName -errorAction SilentlyContinue)) {

      # print error and update secure
      Write-Host "Unfortunately it looks like"
      Write-Host "you $($RED_ESCAPE)don't have $($val.commandName)$($RES_ESCAPE) on your"
      Write-Host "machine!`n"

      Write-Host "Not worry! You can get more"
      Write-Host "info at $($BLU_ESCAPE)$($val.commandName) website:$($RES_ESCAPE)"
      Write-Host "`t$($YEL_ESCAPE)$($val.webLink)$($RES_ESCAPE)`n`n"

      # change holder to false
      $secure = $false
    }
  }

  # return holder
  return $secure
}

# check if this dir have the requirements (for files and folders)
Function checkRequiredItens {

  # secure variable holder
  $secure = $true

  # loop through required itens
  foreach ($val in $requiredItems) {

    # if item doesn't exists
    if (-not (Get-Childitem $val.itemPath -errorAction SilentlyContinue)) {

      # show error
      Write-Host "Unfortunately $($val.itemPath) $($RED_ESCAPE)was not found:$($RES_ESCAPE)"
      Write-Host "  > $($val.errorMessage)`n"

      # update secure variable
      $secure = $false
    }
  }

  # return secure variable
  return $secure
}

Function compileProgram {

  gcc ./setup/kojamp.c -o kojamp
  javac $(Get-Childitem -path ./src -recurse -Include *.java) -d out

}

# when install subcommand is invoked
Function installInvoked {

  # initial alert
  Write-Host "Binaries and bytecodes $($GRE_ESCAPE)are being generated.$($RES_ESCAPE)"
  Write-Host ""

  compileProgram

  $expectedOutputs = @("./kojamp.exe", "./out") # defining expected outputs
  $success = $true # initial success variable as true

  # foreach item in expected outs
  foreach ($item in $expectedOutputs) {

    # if the item was not found
    if (-not (Get-Item $item -errorAction SilentlyContinue)) {

      # show alert
      Write-Host "$($RED_ESCAPE)Could not$($RES_ESCAPE) generate $item"

      # update success var
      $success = $false
    }
  }

  # if it's a fail
  if (-not ($success)) {

    # show message
    Write-Host "`nConsider use $($BLU_ESCAPE)``kjmp reset``$($RES_ESCAPE) or " -NoNewline
    Write-Host "$($GRE_ESCAPE)'reclone'$($RES_ESCAPE) the entire program from:"
    Write-Host "`n`t$($programLink)`n"
  }
}

# when rebuild subcommand is invoked
Function rebuildInvoked {

  if (Get-Item ./out -errorAction SilentlyContinue) {

    Write-Host " $($RED_ESCAPE)>$($RES_ESCAPE) ``out/`` folder $($RED_ESCAPE)has been removed...$($RES_ESCAPE)"
    Remove-Item out -Force -Recurse
  }

  if (Get-Item kojamp.exe -errorAction SilentlyContinue) {

    Write-Host " $($RED_ESCAPE)>$($RES_ESCAPE) ``kojamp.exe`` $($RED_ESCAPE)has been removed...$($RES_ESCAPE)"
    Remove-Item kojamp.exe -Force -Recurse
  }

  Write-Host "`nThe sources outputs are $($GRE_ESCAPE)being generated...$($RES_ESCAPE)`n"
  compileProgram

  if ((Get-Item ./out -errorAction SilentlyContinue) -and (Get-Item kojamp.exe -errorAction SilentlyContinue)) {

    Write-Host "$($GRE_ESCAPE)Success!$($RES_ESCAPE)`n"

  } else {

    Write-Host "Something $($RED_ESCAPE)went wrong!$($RES_ESCAPE)"
    Write-Host "Consider use $($BLU_ESCAPE)``kjmp reset``$($RES_ESCAPE) or $($RED_ESCAPE)open an issue:$($RES_ESCAPE)"
    Write-Host "`t$($programLink)`n"
  }
}


# ----------------------------------------------------------------------
#
# doing some stuff and printing logs on screen
#
# ----------------------------------------------------------------------

# printing top border
Write-Host $TopBorder

# case only main comand was invoked (kjmp)
if ($paramAmount -eq 0) {

  welcomeDisplay
  exit
}

# case sub-commands quantity greater than 1
if ($paramAmount -gt 1) {

  bigArgsAmount
  exit
}

# case sub-command equals "help"
if ($args[0] -eq "help") {

  welcomeDisplay
  exit
}

Write-Host "This may take $($RED_ESCAPE)a while...$($RES_ESCAPE)`n"

if (-not (checkRequiredCommands)) {
  exit
}

if (-not (checkRequiredItens)) {

  Write-Host "Consider use $($BLU_ESCAPE)``kjmp reset``$($RES_ESCAPE) or " -NoNewline
  Write-Host "$($GRE_ESCAPE)'reclone'$($RES_ESCAPE) the entire program from:"
  Write-Host "`n`t$($programLink)`n"
  exit
}

if ($args[0] -eq "install") {

  if ((Get-Item ./out -errorAction SilentlyContinue) -or (Get-Item kojamp.exe -errorAction SilentlyContinue)) {

    Write-Host "Some outputs are $($YEL_ESCAPE)already here$($RES_ESCAPE)"
    Write-Host "Consider use $($BLU_ESCAPE)``kjmp rebuild``$($RES_ESCAPE) instead`n"

    exit
  }

  installInvoked
  exit
}

if ($args[0] -eq "rebuild") {

  if (-not (Get-Item ./out -errorAction SilentlyContinue) -and -not (Get-Item kojamp.exe -errorAction SilentlyContinue)) {

    Write-Host "You still $($RED_ESCAPE)don't have$($RES_ESCAPE) the $($YEL_ESCAPE)out folder$($RES_ESCAPE) or the $($YEL_ESCAPE)executable$($RES_ESCAPE)"
    Write-Host "Consider use $($BLU_ESCAPE)``kjmp install``$($RES_ESCAPE) instead!`n"
    exit
  }

  rebuildInvoked
  exit
}

if ($args[0] -eq "reset") {

  Write-Host "The $($YEL_ESCAPE)``reset``$($RES_ESCAPE) command $($RED_ESCAPE)does not work for now.$($RES_ESCAPE)"
  Write-Host "I will still work on it in the future.`n"
  exit
}

Write-Host "Command $($RED_ESCAPE)not recognized:$($RES_ESCAPE) $($UND_ESCAPE)$($args[0])$($RES_ESCAPE)"
Write-Host "Try $($BLU_ESCAPE)``kjmp``$($RES_ESCAPE) or $($BLU_ESCAPE)``kjmp help``$($RES_ESCAPE) instead!`n"
