<GameProjectFile>
  <PropertyGroup Type="Layer" Name="Maze" ID="6ffeaf4b-263b-4d48-a3df-7eca13216e0c" Version="2.0.0.0" />
  <Content ctype="GameProjectContent">
    <Content>
      <Animation Duration="0" Speed="1.0000" />
      <ObjectData Name="Layer" CanEdit="False" FrameEvent="" ComboBoxIndex="1" ColorAngle="0.0000" ctype="PanelObjectData">
        <Position X="0.0000" Y="0.0000" />
        <Scale ScaleX="1.0000" ScaleY="1.0000" />
        <AnchorPoint />
        <CColor A="255" R="255" G="255" B="255" />
        <Size X="1136.0000" Y="640.0000" />
        <PrePosition X="0.0000" Y="0.0000" />
        <PreSize X="0.0000" Y="0.0000" />
        <Children>
          <NodeObjectData Name="maze_bg" ActionTag="-2037883432" FrameEvent="" Tag="4" ObjectIndex="1" ctype="SpriteObjectData">
            <Position X="568.0000" Y="320.0000" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <CColor A="255" R="255" G="255" B="255" />
            <Size X="854.0000" Y="640.0000" />
            <PrePosition X="0.5000" Y="0.5000" />
            <PreSize X="0.0000" Y="0.0000" />
            <FileData Type="PlistSubImage" Path="roomBg.png" Plist="maze.plist" />
          </NodeObjectData>
          <NodeObjectData Name="btn_exit" ActionTag="1122526104" FrameEvent="" Tag="5" ObjectIndex="1" TouchEnable="True" FontSize="36" ButtonText="退出" Scale9Width="85" Scale9Height="85" ctype="ButtonObjectData">
            <Position X="921.5002" Y="63.0000" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <CColor A="255" R="255" G="255" B="255" />
            <Size X="85.0000" Y="85.0000" />
            <PrePosition X="0.8112" Y="0.0984" />
            <PreSize X="0.0000" Y="0.0000" />
            <TextColor A="255" R="65" G="65" B="70" />
            <DisabledFileData Type="Default" Path="Default/Button_Disable.png" />
            <PressedFileData Type="Default" Path="Default/Button_Press.png" />
            <NormalFileData Type="Default" Path="Default/Button_Normal.png" />
          </NodeObjectData>
          <NodeObjectData Name="icon" ActionTag="-165071812" FrameEvent="" Tag="7" ObjectIndex="3" ctype="SpriteObjectData">
            <Position X="923.7850" Y="472.3572" />
            <Scale ScaleX="0.8000" ScaleY="0.8000" />
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <CColor A="255" R="255" G="255" B="255" />
            <Size X="118.0000" Y="187.0000" />
            <PrePosition X="0.8132" Y="0.7381" />
            <PreSize X="0.0000" Y="0.0000" />
            <FileData Type="PlistSubImage" Path="roomPlayerIcon.png" Plist="maze.plist" />
          </NodeObjectData>
          <NodeObjectData Name="goldLabel" ActionTag="165297543" FrameEvent="" Tag="12" ObjectIndex="1" FontSize="36" LabelText="99991" IsCustomSize="True" ctype="TextObjectData">
            <Position X="936.1074" Y="600.1429" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <CColor A="255" R="255" G="255" B="255" />
            <Size X="100.0000" Y="42.0000" />
            <PrePosition X="0.8240" Y="0.9377" />
            <PreSize X="0.0000" Y="0.0000" />
          </NodeObjectData>
          <NodeObjectData Name="hpLabel" ActionTag="739606969" FrameEvent="" Tag="13" ObjectIndex="2" FontSize="24" LabelText="40/100" ctype="TextObjectData">
            <Position X="941.1077" Y="353.1438" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <CColor A="255" R="255" G="255" B="255" />
            <Size X="73.0000" Y="28.0000" />
            <PrePosition X="0.8284" Y="0.5518" />
            <PreSize X="0.0000" Y="0.0000" />
          </NodeObjectData>
          <NodeObjectData Name="btn_hp" ActionTag="1357738933" FrameEvent="" Tag="10" ObjectIndex="2" TouchEnable="True" FontSize="14" ButtonText="" Scale9Width="122" Scale9Height="121" ctype="ButtonObjectData">
            <Position X="923.5000" Y="211.0000" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <CColor A="255" R="255" G="255" B="255" />
            <Size X="122.0000" Y="121.0000" />
            <PrePosition X="0.8129" Y="0.3297" />
            <PreSize X="0.0000" Y="0.0000" />
            <TextColor A="255" R="65" G="65" B="70" />
            <DisabledFileData Type="PlistSubImage" Path="roomBtnHeal0.png" Plist="maze.plist" />
            <PressedFileData Type="PlistSubImage" Path="roomBtnHeal2.png" Plist="maze.plist" />
            <NormalFileData Type="PlistSubImage" Path="roomBtnHeal1.png" Plist="maze.plist" />
          </NodeObjectData>
          <NodeObjectData Name="numBg" ActionTag="-888905298" FrameEvent="" Tag="20" ObjectIndex="1" Scale9Width="55" Scale9Height="55" ctype="ImageViewObjectData">
            <Position X="889.5000" Y="281.0000" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <CColor A="255" R="255" G="255" B="255" />
            <Size X="55.0000" Y="55.0000" />
            <PrePosition X="0.7830" Y="0.4391" />
            <PreSize X="0.0000" Y="0.0000" />
            <FileData Type="PlistSubImage" Path="roomNumberOfHeal.png" Plist="maze.plist" />
          </NodeObjectData>
          <NodeObjectData Name="numLabel" ActionTag="208658315" FrameEvent="" Tag="14" ObjectIndex="3" FontSize="24" LabelText="99" ctype="TextObjectData">
            <Position X="890.1220" Y="281.1439" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <CColor A="255" R="255" G="56" B="0" />
            <Size X="26.0000" Y="28.0000" />
            <PrePosition X="0.7836" Y="0.4393" />
            <PreSize X="0.0000" Y="0.0000" />
          </NodeObjectData>
        </Children>
        <SingleColor A="255" R="0" G="0" B="0" />
        <FirstColor A="255" R="0" G="0" B="0" />
        <EndColor A="255" R="255" G="255" B="255" />
        <ColorVector ScaleX="1.0000" ScaleY="0.0000" />
      </ObjectData>
    </Content>
  </Content>
</GameProjectFile>