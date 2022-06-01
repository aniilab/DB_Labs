using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;

namespace MovieBase
{
    public partial class ActorsInMovie
    {
        public int Id { get; set; }
        [Display(Name = "Актор")]
        public int ActorId { get; set; }
        [Display(Name = "Фільм")]
        public int MovieId { get; set; }
        [Display(Name = "Роль")]
        public string Role { get; set; } = null!;

        [Display(Name = "Актор")]
        public virtual Actor? Actor { get; set; } = null!;
        [Display(Name = "Фільм")]
        public virtual Movie? Movie { get; set; } = null!;
    }
}
